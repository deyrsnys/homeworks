/*
Float
Колчин, 171
*/

#include <stdio.h>
#include <math.h>
#include <conio.h>

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

			// õèòðèì ñ óêàçàòåëÿìè
			int number = * (int *) & a;
			// ýòî ÷èñëî ïðèãîäèòñÿ êàê ïîáèòîâîå ïðåäñòàâëåíèå èñõîäíîãî float	
			split_float_way1(number);

			system("pause");
		} 
		else if( ch == '2')
		{
			union							// Äåëàåì îáúåäèíåíèå.
			{
					int number_int;
					float number_float;
			} mega_number;

			printf("Enter float number: ");
			scanf("%f",&(mega_number.number_float));				// ââîäèì ôëîàòîâñêîå ÷èñëî
		    printf("Initial float: %f\n",mega_number.number_float);
			split_float_way1(mega_number.number_int); 				// â ôóíêöèþ ïåðåäàåì int-îâñêîå ÷èñëî èç îáúåäèíåíèÿ
			system("pause");
		}
		else if( ch == '3')
		{
			union{
				float number_float;
				
				struct {
					unsigned mantissa : 23; // Ïåðâûå 23 áèòà
					unsigned order : 8;	// Ñëåäóþùèå 8 áèò
					unsigned sign : 1;	// Ïîñëåäíèé áèò, áóäåò îòâå÷àòü çà çíàê
				} float_skelet;

			} mega_number2;
				
				
			printf("Enter float number: ");
			scanf("%f",&mega_number2.number_float);				// Ââîäèì ÷èñëî
		    printf("Initial float: %f\n", mega_number2.number_float);
			
			// ìîæíî ïðîâåðèòü ÷òî â íèõ õðàíèòñÿ
			//printf("%d ",mega_number2.float_skelet.sign);
			//printf("%d ",mega_number2.float_skelet.order);
			//printf("%d ",mega_number2.float_skelet.mantissa);
			
			// Ïåðåäàåì çíàê, ìàíòèññó, è ïîðÿäîê â ôóíêöèþ.
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
	// Ñ ïîìîùüþ óêàçàòåëåé.
	// Íåîáõîäèìî ïîëó÷èòü çíàê(1áèò), ïîðÿäîê(8 áèò) è ìàíòèññó(23 áèòà)
	
	// Ïîëó÷èì çíàê
	int sign = (number >> 31)?-1:1;
	
	//printf("%c", sign<0?'-':'+');

	// Ñëåäóþùèå 8 áèò óêàçûâàþò íà ïîðÿäîê
	int order = ((number >> 23) & (( 1 << 8) - 1)) - 127;			// Ïîëó÷àåì ýòè 8 áèò
	//printf("%d \n",order);
	
	// Îñòàëîñü ïîëó÷èòü ìàíòèññó, íà íåå îòâîäèòñÿ 23 áèòà.
	int pre_mantissa = number & ((1 << 23) - 1);
	
	//printf("%d \n",pre_mantissa);
	//for(int i = 31; i >= 0; i--)
		//printf("%d",(new_number>>i)&1);

	// http://www.softelectro.ru/ieee754.html
	// Âîñïîëüçóåìñÿ ôîðìóëîé è íàéäåì ìàíòèññó 
	float mantissa = (float)pre_mantissa/(1<<23);
	
	//// Ïðîâåðêà íà ïðàâèëüíîñòü
	//// printf("\n%f", (float)(1+mantissa)*(float)sign*(float)pow(2.0,order));  // ôîðìóëà ñ ñàéòà


	// Âîîáùå âñå íàéäåíî, òåïåðü âûâîä íà ýêðàí
	// Íóæíî ó÷åñòü ñëó÷àè, êîãäà float åñòü +-áåñêîíå÷íîñòü, íóëü, èëè NaN
	
	printf("Result representation: ");
	if( !(order+127) && !mantissa )				// Ñëó÷àé íóëÿ
		printf("Zero\n");
	else if ( order == 128 && !mantissa )			// Áåñêîíå÷íîñòè
		printf("%cInfinity\n",sign<0?'-':'+');
	else if ( order == 128 && mantissa)
		printf("NaN\n");
	else 
		printf("(%d) * 2^(%d) * (1 + %f)\n", sign, order, mantissa);	
	
	printf("\n");
}



void split_float_way2(int number){
 	// Íå íóæíà, âñ¸ äåëàåò ïåðâàÿ ôóíêöèÿ

}
void split_float_way3(int sign, int order, int pre_mantissa){
	
	// Ïîëó÷èì çíàê
	sign = (sign)?-1:1;

	// Êîððåêòèðóåì ïîðÿäîê
	order = order - 127;			// â ñîîòâåòñòâèè ñ ôîðìóëîé îòíèìàåì 127
	//printf("%d \n",order);
		
	//printf("%d \n",pre_mantissa);

	// http://www.softelectro.ru/ieee754.html
	// Âîñïîëüçóåìñÿ ôîðìóëîé è íàéäåì ìàíòèññó 
	float mantissa = (float)pre_mantissa/(1<<23);
	
	//// Ïðîâåðêà íà ïðàâèëüíîñòü
	//// printf("\n%f", (float)(1+mantissa)*(float)sign*(float)pow(2.0,order));  // ôîðìóëà ñ ñàéòà


	// Âîîáùå âñå íàéäåíî, òåïåðü âûâîä íà ýêðàí
	// Íóæíî ó÷åñòü ñëó÷àè, êîãäà float åñòü +-áåñêîíå÷íîñòü, íóëü, èëè NaN
	
	printf("Result representation: ");
	if( !(order+127) && !mantissa )				// Ñëó÷àé íóëÿ
		printf("Zero\n");
	else if ( order == 128 && !mantissa )			// Áåñêîíå÷íîñòè
		printf("%cInfinity\n",sign<0?'-':'+');
	else if ( order == 128 && mantissa)
		printf("NaN\n");
	else 
		printf("(%d) * 2^(%d) * (1 + %f)\n", sign, order, mantissa);	
	
	printf("\n");


}
