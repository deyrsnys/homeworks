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
	
	strcpy(buf,p);
}

 

void AnotherFunction()
{
	printf("Broken\n");
}


int main(void)
{
	printf("%p\n", &AnotherFunction); 	// Âûâîä àäðåñà ôóíêöèè 00403010
	InsertString();
	return 0;
}
