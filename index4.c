#include <stdio.h>

int main(int argv, char* args[])
{
	int number = 16 ;
	int bits = 16;                   // –азмер ограничен 32
	
	


for(int i = 0; i < 6; ++i)
	{
	
	printf("\nNumber: ");
	scanf("%d", &number);
	printf("Base: ");
	scanf("%d", &bits);
	
	if (bits > 32){		// больше быть может. » это зависит от компьютера.
		bits = 32;
		printf("Base can't be more than 32. Base: 32\n");
		}

	// ѕусть например bits = 5. т.е. имеетс€ 5 бит. 
	// —тарший бит указывает на знак, значит дл€ самого числа остаетс€ 4 бита
	// 5 бит достаточно дл€ хранени€ чисел от -16 до 15

	// ¬ообще говор€, какое бы число мы не ввели в number. представление его 
	// в n - разр€дной машине будет следующее
	int _a = number<<(31-bits+1)>>(31-bits+1);
	
	// ќсталось сравинть числа _a и number
	int _b = abs(number - _a);			// ≈сли тут ноль, то все гуд, иначе не гуд
	
	// вывод ответа
	printf("For number %d answer is %d\n\n", number, (((~_b)+1)>>31 ) + 1);
}
	

	return 0;
}
