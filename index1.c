#include <stdio.h>

// Двоичное представление числа.

// Объявление функций:
void DecimalToBinary(unsigned int);
void DecToBin(unsigned int n);
void DecToBin2(unsigned int n); 


void main(void){
	// Перевести число из десятичной СС в двоичную используя побитовые операции
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);

	// Использование функции без рекурсии
	printf("Without Recursion: ");
	DecimalToBinary(n);
	
	// Использование функции с рекурсией
	printf("\n\nWith Recursion: ");
	DecToBin(n);

	// Еще один способ
	printf("\n\nAnother way: ");
	DecToBin2(n);
	printf("\n\n");
	
}

void DecimalToBinary(unsigned int n){
  	// Без рекурсиии
	
		// Сохраняем результат в str
	char* str = (char*)malloc(32);
	
		// Пока n не равно нулю выполняем цикл. 
	do{	
		// Получаем последнюю цифру двоичного представления числа и дописываем его в str	
		sprintf(str,"%s%d",str,n&1);
		// Смещение на 1 позицию вправо.
			/* Если n = 5, то в двоичном представлении n равняется 101
				Если сдвинем 101 на одну позицию вправо, то получим двоичное число 10.
			*/
		n = n >> 1;			
	}while(n);

		// В итоге получаем двоичную запись числа, но в обратном порядке.
		// Необходимо вывести строку в обратном порядке.
		
		// Для этого, установим указатель на конец строки
	char *p = str;			// Создаем указатель на строку с результатом
	
	// Ищем конец этой строки			
	while(*p)
	{
		p++;
	} 
	// Теперь указатель указывает на конец строки.
	
	// Выводим строку в обратном порядке						
	do {
		p--;
		printf("%c",*p);		
	} while(p != str );

	// Обнуляем указатели высвобождаем память.
	p = NULL;
	free(str);
	str = NULL;	

}

void DecToBin(unsigned int n){
	// С рекурсией
	if(!n)
		return;
	DecToBin(n>>1);
	printf("%d",n&1);

}

void DecToBin2(unsigned int n){
	for( int i = 31; i >=0; i-- )
	{
		printf("%d",(n>>i)&1);
	}
}
