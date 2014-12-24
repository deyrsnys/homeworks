#include <stdio.h>
#include <math.h>
#include <conio.h>
// ������� float


void split_float_way1(int number);
void split_float_way2(int number);
void split_float_way3(int sign, int order, int pre_mantissa);

int main(int argv, char* args[])
{
	char ch = '\0';
	
	do{
		//system("cls");
		printf("\nChoose your way and press Enter \n 1. Way 1 (pointers) \n 2. Way 2 (unions) \n 3. Way 3 (bit fields) \n 0. Exit \n>");
		//scanf("%d",&choose);
		ch = _getche();
		printf("\n");
		if (ch == '1')
		{	
			float a = .0/0;
			printf("Enter float number: ");
			scanf("%f",&a);
		    printf("Initial float: %f\n",a);

			// ������ � �����������
			int number = * (int *) & a;
			// ��� ����� ���������� ��� ��������� ������������� ��������� float	
			split_float_way1(number);

			system("pause");
		} 
		else if( ch == '2')
		{
			union							// ������ �����������.
			{
					int number_int;
					float number_float;
			} mega_number;

			printf("Enter float number: ");
			scanf("%f",&(mega_number.number_float));				// ������ ����������� �����
		    printf("Initial float: %f\n",mega_number.number_float);
			split_float_way1(mega_number.number_int); 				// � ������� �������� int-������ ����� �� �����������
			system("pause");
		}
		else if( ch == '3')
		{
			union{
				float number_float;
				
				struct {
					unsigned mantissa : 23; // ������ 23 ����
					unsigned order : 8;	// ��������� 8 ���
					unsigned sign : 1;	// ��������� ���, ����� �������� �� ����
				} float_skelet;

			} mega_number2;
				
				
			printf("Enter float number: ");
			scanf("%f",&mega_number2.number_float);				// ������ �����
		    printf("Initial float: %f\n", mega_number2.number_float);
			
			// ����� ��������� ��� � ��� ��������
			//printf("%d ",mega_number2.float_skelet.sign);
			//printf("%d ",mega_number2.float_skelet.order);
			//printf("%d ",mega_number2.float_skelet.mantissa);
			
			// �������� ����, ��������, � ������� � �������.
			split_float_way3(mega_number2.float_skelet.sign, mega_number2.float_skelet.order, mega_number2.float_skelet.mantissa);

			system("pause");
		}
		else if (ch != '0')
		{
			continue;
		}
	} while(ch != '0');
	
	return 0 ;
}


void split_float_way1(int number){
	// � ������� ����������.
	// ���������� �������� ����(1���), �������(8 ���) � ��������(23 ����)
	
	// ������� ����
	int sign = (number >> 31)?-1:1;
	
	//printf("%c", sign<0?'-':'+');

	// ��������� 8 ��� ��������� �� �������
	int order = ((number >> 23) & (( 1 << 8) - 1)) - 127;			// �������� ��� 8 ���
	//printf("%d \n",order);
	
	// �������� �������� ��������, �� ��� ��������� 23 ����.
	int pre_mantissa = number & ((1 << 23) - 1);
	
	//printf("%d \n",pre_mantissa);
	//for(int i = 31; i >= 0; i--)
		//printf("%d",(new_number>>i)&1);

	// http://www.softelectro.ru/ieee754.html
	// ������������� �������� � ������ �������� 
	float mantissa = (float)pre_mantissa/(1<<23);
	
	//// �������� �� ������������
	//// printf("\n%f", (float)(1+mantissa)*(float)sign*(float)pow(2.0,order));  // ������� � �����


	// ������ ��� �������, ������ ����� �� �����
	// ����� ������ ������, ����� float ���� +-�������������, ����, ��� NaN
	
	printf("Result representation: ");
	if( !(order+127) && !mantissa )				// ������ ����
		printf("Zero\n");
	else if ( order == 128 && !mantissa )			// �������������
		printf("%cInfinity\n",sign<0?'-':'+');
	else if ( order == 128 && mantissa)
		printf("NaN\n");
	else 
		printf("(%d) * 2^(%d) * (1 + %f)\n", sign, order, mantissa);	
	
	printf("\n");
}



void split_float_way2(int number){
 	// �� �����, �� ������ ������ �������

}
void split_float_way3(int sign, int order, int pre_mantissa){
	
	// ������� ����
	sign = (sign)?-1:1;

	// ������������ �������
	order = order - 127;			// � ������������ � �������� �������� 127
	//printf("%d \n",order);
		
	//printf("%d \n",pre_mantissa);

	// http://www.softelectro.ru/ieee754.html
	// ������������� �������� � ������ �������� 
	float mantissa = (float)pre_mantissa/(1<<23);
	
	//// �������� �� ������������
	//// printf("\n%f", (float)(1+mantissa)*(float)sign*(float)pow(2.0,order));  // ������� � �����


	// ������ ��� �������, ������ ����� �� �����
	// ����� ������ ������, ����� float ���� +-�������������, ����, ��� NaN
	
	printf("Result representation: ");
	if( !(order+127) && !mantissa )				// ������ ����
		printf("Zero\n");
	else if ( order == 128 && !mantissa )			// �������������
		printf("%cInfinity\n",sign<0?'-':'+');
	else if ( order == 128 && mantissa)
		printf("NaN\n");
	else 
		printf("(%d) * 2^(%d) * (1 + %f)\n", sign, order, mantissa);	
	
	printf("\n");


}
