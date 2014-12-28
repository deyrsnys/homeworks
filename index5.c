/*
Float
Колчин, 171
*/

#include <stdio.h>
#include <math.h>
#include <conio.h>
// Разбить float


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

			// хитрим с указателями
			int number = * (int *) & a;
			// это число пригодится как побитовое представление исходного float	
			split_float_way1(number);

			system("pause");
		} 
		else if( ch == '2')
		{
			union							// Делаем объединение.
			{
					int number_int;
					float number_float;
			} mega_number;

			printf("Enter float number: ");
			scanf("%f",&(mega_number.number_float));				// вводим флоатовское число
		    printf("Initial float: %f\n",mega_number.number_float);
			split_float_way1(mega_number.number_int); 				// в функцию передаем int-овское число из объединения
			system("pause");
		}
		else if( ch == '3')
		{
			union{
				float number_float;
				
				struct {
					unsigned mantissa : 23; // Первые 23 бита
					unsigned order : 8;	// Следующие 8 бит
					unsigned sign : 1;	// Последний бит, будет отвечать за знак
				} float_skelet;

			} mega_number2;
				
				
			printf("Enter float number: ");
			scanf("%f",&mega_number2.number_float);				// Вводим число
		    printf("Initial float: %f\n", mega_number2.number_float);
			
			// можно проверить что в них хранится
			//printf("%d ",mega_number2.float_skelet.sign);
			//printf("%d ",mega_number2.float_skelet.order);
			//printf("%d ",mega_number2.float_skelet.mantissa);
			
			// Передаем знак, мантиссу, и порядок в функцию.
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
	// С помощью указателей.
	// Необходимо получить знак(1бит), порядок(8 бит) и мантиссу(23 бита)
	
	// Получим знак
	int sign = (number >> 31)?-1:1;
	
	//printf("%c", sign<0?'-':'+');

	// Следующие 8 бит указывают на порядок
	int order = ((number >> 23) & (( 1 << 8) - 1)) - 127;			// Получаем эти 8 бит
	//printf("%d \n",order);
	
	// Осталось получить мантиссу, на нее отводится 23 бита.
	int pre_mantissa = number & ((1 << 23) - 1);
	
	//printf("%d \n",pre_mantissa);
	//for(int i = 31; i >= 0; i--)
		//printf("%d",(new_number>>i)&1);

	// http://www.softelectro.ru/ieee754.html
	// Воспользуемся формулой и найдем мантиссу 
	float mantissa = (float)pre_mantissa/(1<<23);
	
	//// Проверка на правильность
	//// printf("\n%f", (float)(1+mantissa)*(float)sign*(float)pow(2.0,order));  // формула с сайта


	// Вообще все найдено, теперь вывод на экран
	// Нужно учесть случаи, когда float есть +-бесконечность, нуль, или NaN
	
	printf("Result representation: ");
	if( !(order+127) && !mantissa )				// Случай нуля
		printf("Zero\n");
	else if ( order == 128 && !mantissa )			// Бесконечности
		printf("%cInfinity\n",sign<0?'-':'+');
	else if ( order == 128 && mantissa)
		printf("NaN\n");
	else 
		printf("(%d) * 2^(%d) * (1 + %f)\n", sign, order, mantissa);	
	
	printf("\n");
}



void split_float_way2(int number){
 	// Не нужна, всё делает первая функция

}
void split_float_way3(int sign, int order, int pre_mantissa){
	
	// Получим знак
	sign = (sign)?-1:1;

	// Корректируем порядок
	order = order - 127;			// в соответствии с формулой отнимаем 127
	//printf("%d \n",order);
		
	//printf("%d \n",pre_mantissa);

	// http://www.softelectro.ru/ieee754.html
	// Воспользуемся формулой и найдем мантиссу 
	float mantissa = (float)pre_mantissa/(1<<23);
	
	//// Проверка на правильность
	//// printf("\n%f", (float)(1+mantissa)*(float)sign*(float)pow(2.0,order));  // формула с сайта


	// Вообще все найдено, теперь вывод на экран
	// Нужно учесть случаи, когда float есть +-бесконечность, нуль, или NaN
	
	printf("Result representation: ");
	if( !(order+127) && !mantissa )				// Случай нуля
		printf("Zero\n");
	else if ( order == 128 && !mantissa )			// Бесконечности
		printf("%cInfinity\n",sign<0?'-':'+');
	else if ( order == 128 && mantissa)
		printf("NaN\n");
	else 
		printf("(%d) * 2^(%d) * (1 + %f)\n", sign, order, mantissa);	
	
	printf("\n");


}


