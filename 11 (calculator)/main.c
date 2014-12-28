#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Long_num.h"
#include "Math_operations.h"
#include "stack.h"

int  main(int argc, char **argv)		 
{
	FILE* fileIn = NULL;				 
	FILE* fileOut = NULL;				 
	Long_num* A = Long_init();			 
	Long_num* B = Long_init();			 
	Long_num* Res = Long_init();		 
	Stack* stack = Stack_init();		 
	char c;								 
	int i = 0;							 
	int kod = 0;						 
	char* kommand = (char*)malloc(2000*sizeof(char));	 
	if (argc > 1)						 
	{
		fileIn = freopen(argv[1], "r", stdin);		 
		if (fileIn == NULL)							 
		{						
			fprintf(stderr, "File IO error.\n");
			return 1;
		}
	}
	if (argc > 2)						 
	{
		fileOut = freopen(argv[2], "w", stdout);
	}
	c = getchar();						 
	while (c != EOF)					 
	{
		i = 0;							 
		while ((c != ' ') && (c != '\n') && (c != EOF))		 
		{
			kommand[i] = c;				 
			c = getchar();				 
			i++;
		}
		kommand[i] = '\0';			
		if ((i == 1) && (kommand[0] != '+') && (kommand[0] != '-') && (kommand[0] != '*') && (kommand[0] != '/') && (kommand[0] != '=') && ((kommand[0] < '0')||(kommand[0] >'9')))		 
		{
			printf("Unknown command\n");		 
			Stack_clear(stack);					 
			return 1;							 
		}
		else
		if ((kommand[0]>='0') && (kommand[0]<='9') || ((kommand[0]=='-')&&(i>1)))		 
			{
				A = Read_Long(kommand, i, &kod);			 
				if (kod != -1)								 
				{
					printf("Unknown command\n");			 
					Stack_clear(stack);
					return 1;								 
				}
				Stack_push_top(stack, A);					 
			}
		else												 
				if ((i == 1) && (kommand[0] == '='))		 
				{
					if (stack->Size == 0)					 
					{
						printf("Not enough arguments\n");	 
						Stack_clear(stack);
						return 1;							 
					}
					printf("%s\n", Long_print(stack->head->data));	 
				}
				else										 
				{
					if (stack->Size < 2)					 
					{
						printf("Not enough arguments\n");
						Stack_clear(stack);
						return 1;
					}
					A = Stack_pop_top(stack);				 
					B = Stack_pop_top(stack);				 
					switch (kommand[0])						 
					{
						case '+':							 
						{
							Res = Plus(A, B, 0);
							Long_clear(A);
							Long_clear(B);
							break;
						}
						case '-':							 
						{
							Res = Minus(A, B, 0);
							Long_clear(A);
							Long_clear(B);
							break;
						}
						case '*':							 
						{
							Res = Product(A, B);
							Long_clear(A);
							Long_clear(B);
							break;
						}
						case '/':							 
						{
							if ((B->Size == 1) && (B->head->data == 0))			 
							{
								printf("Division by zero\n");				 
								Stack_clear(stack);
								return 1;							 
							}
							Res = Div(A, B);			 
							Long_clear(A);
							Long_clear(B);
							break;
						}
					}
					Stack_push_top(stack, Res);			 
				}
				c = getchar();							 
	}
	Stack_print(stack);					 
	Stack_clear(stack);					 
	return 0;							 
}