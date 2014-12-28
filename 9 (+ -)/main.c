#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Long_num.h"

Long_num* Minus(Long_num* A, Long_num* B, int change);			 
 
Long_num* Plus(Long_num* A, Long_num* B, int change)			 
{
	Long_num* Ans = Long_init();					 
	node* temp_A = A->head;							 
	node* temp_B = B->head;							 
	int sum = 0;									 
	if ((A->sign != B->sign)&&(change == 0	))		 
	{
		Ans = Minus(A, B, 1);							 
		return Ans;
	}
	while ((temp_A != NULL) || (temp_B != NULL))	 
	{
		if (temp_A != NULL)							 
		{
			sum = sum + temp_A->data;				 
			temp_A = temp_A->next;					 
		}
		if (temp_B != NULL)							 
		{
			sum = sum + temp_B->data;				 
			temp_B = temp_B->next;					 
		}
		Long_add_left(Ans, sum % 10);				 
 		sum = (int)(sum / 10);						 
	}
	if (sum != 0)									 
		Long_add_left(Ans, sum % 10);
	Ans->sign = A->sign;							 
	return Ans;
}

Long_num* Minus(Long_num* A, Long_num* B, int change)			 
{
	Long_num* Ans = Long_init();
	node* temp_A = A->head;
	node* temp_B = B->head;
	node* temp_Ans = Ans->head;						 
	int razn = 0;									 
	int swap = 1;									 
	if ((A->sign != B->sign)&&(change==0))			 
	{		
		Ans = Plus(A, B, 1);							 
		return Ans;
	}
	if (A->Size < B->Size)							 
	{
		temp_A = B->head;
		temp_B = A->head;
		swap = -1;
	}
	while ((temp_A != NULL) || (temp_B != NULL))	 
	{
		if (temp_A != NULL)							 
		{
			razn = razn + temp_A->data;				 
			temp_A = temp_A->next;					 
		}
		if (temp_B != NULL)							 
		{
			razn = razn - temp_B->data;				 
			temp_B = temp_B->next;					 
		}
		if (razn < 0)								 
		{
			Long_add_left(Ans, razn + 10);			 
			razn = -1;								 
		}
		else										 
		{
			Long_add_left(Ans, razn);				 
			razn = 0;								 
		}
	}
	if (razn == -1)									 
	{
		temp_Ans = Ans->head;
		temp_Ans->data = 10 - temp_Ans->data;		 
		temp_Ans = temp_Ans->next;
		while (temp_Ans != NULL)					 
		{											 
			temp_Ans->data = 9 - temp_Ans->data;	 
			temp_Ans = temp_Ans->next;				 
		}
		Ans->sign = -1;								 
	}
	Long_remove_zero(Ans);							 
	Ans->sign = Ans->sign * A->sign * swap;			 
	return Ans;
}

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
	if ((strlen(c) != 1) || ((c[0] != '+') && (c[0] != '-')))		 
	{
		printf("Incorrect operation\n");
		getch();
		return;
	}
	if (c[0] == '+')
		Res = Plus(A, B, 0);
	else
		Res = Minus(A, B, 0);
	printf("Res = \n%s", Long_print(Res));			 
	Long_clear(A);
	Long_clear(B);
	Long_clear(Res);
	getch();
	return;
}