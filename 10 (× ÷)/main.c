#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Long_num.h"
#include "Math_operations.h"

void main()
{
	Long_num* A = Long_init();
	Long_num* B = Long_init();
	Long_num* Res = Long_init();
	char c[255];
	int kod = 0;
	printf("Insert A:\n");
	scanf("%s", c);
	A = Read_Long(c, strlen(c), &kod);
	if (kod != -1)									 
	{
		printf("Incorrect A\n");
		getch();
		return;
	}
	printf("Insert B:\n");
	scanf("%s", c);
	B = Read_Long(c, strlen(c), &kod);
	if (kod != -1)									 
	{
		printf("Incorrect B\n");
		getch();
		return;
	}
	printf("Insert operation:\n");
	scanf("%s", c);
	if ((strlen(c) != 1) || ((c[0] != '*') && (c[0] != '/')))		 
	{
		printf("Incorrect operation\n");
		getch();
		return;
	}
	if (c[0] == '*')
		Res = Product(A, B);
	else
		Res = Div(A, B);
	printf("Res = \n%s", Long_print(Res));			 
	Long_clear(A);
	Long_clear(B);
	Long_clear(Res);
	getch();
	return;
}
