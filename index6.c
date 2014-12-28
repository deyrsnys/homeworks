/*
Переполняя буфер вызываем постороннюю функцию
Колчин, 171
*/

#include <stdio.h>

#pragma check_stack(off)

void InsertString()
{
	char buf[4];
	char p[] = "AAAABBBB"
		"\x40\x10\x40\x00" 
		"AAA";
	
	strcpy(buf,p); //strcpy позволяет записать больше данных, чем вмещает выделенный под них массив
}

 

void AnotherFunction()
{
	printf("Broken\n");
}


int main(void)
{
	printf("%p\n", &AnotherFunction); 	// Вывод адреса функции 00401040
	InsertString();
	return 0;
}
