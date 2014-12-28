#include <stdio.h>
#include <stdlib.h>
#include "Long_num.h"
#include "Math_operations.h"

Long_num* Plus(Long_num* A, Long_num* B, int change)			 
{
	Long_num* Ans = Long_init();					 
	node* temp_A = A->head;							 
	node* temp_B = B->head;							 
	int sum = 0;									 
	if ((A->sign != B->sign) && (change == 0))		 
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
	if ((A->sign != B->sign) && (change == 0))			 
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

Long_num* Product(Long_num* A, Long_num* B)			 
{
	Long_num* Ans = Long_init();					 
	Long_num* Pre_Ans = Long_init();				 
	node* temp_A = A->head;							 
	node* temp_A1 = temp_A;							 
	node* temp_B = B->head;							 
	int value = 0;									 
	int prod = 0;									 
	int pow_of_ten = 0;								 
	int i = 0;					
	Long_add_right(Ans, 0);							 
	if ((A->Size == 0) || (B->Size == 0))			 
		return Ans;									 
	if (((A->Size == 1) && (A->head->data == 0)) || ((B->Size == 1) && (B->head->data == 0)))		 
	{
		Ans->Size = 1;
		return Ans; 
	}
	if ((A->Size == 1) && (A->head->data == 1))			 
	{
		Ans = Plus(Ans, B, 0);							 
		Ans->sign = Ans->sign * A->sign;				 
		return Ans;
	}
	if ((B->Size == 1) && (B->head->data == 1))			 
	{
		Plus(Ans, A, 0);
		Ans->sign = Ans->sign * B->sign;
		return Ans;
	}
	if (A->Size < B->Size)								 
	{
		temp_A = B->head;
		temp_B = A->head;
		temp_A1 = temp_A;
	}
	while (temp_B != NULL)								 
	{
		value = temp_B->data;							 
		prod = 0;										 
		while (temp_A != NULL)							 
		{
			prod = prod + temp_A->data * value;			 
			Long_add_left(Pre_Ans, prod % 10);			 
			prod = (int)(prod / 10);					 
			temp_A = temp_A->next;						 
		}
		if (prod != 0)									 
			Long_add_left(Pre_Ans, prod);				 
		for (i = 0; i < pow_of_ten; i++)				 
			Long_add_right(Pre_Ans, 0);
		Ans = Plus(Ans, Pre_Ans, 0);					 
		temp_B = temp_B->next;							 
		temp_A = temp_A1;								 
		pow_of_ten++;									
		Long_clear(Pre_Ans);							 
		Pre_Ans = Long_init();							 
	}
	Long_remove_zero(Ans);								 
	Ans->sign = A->sign * B->sign;						 
	return Ans;
}

Long_num* Div(Long_num* A, Long_num* B)					 
{
	Long_num* Ans = Long_init();
	Long_num* B_zeros = Copy(B);
	Long_num* K = Long_init();
	Long_num* A_copy = Copy(A);
	node* temp_A = A->head;
	node* temp_B = B->head;
	int i = 0;
	int div = 0;
	if ((A->Size == 0) || (B->Size == 0))			 
		return Ans;									 
	if ((B->Size == 1) && (B->head->data == 0))
	{
		printf("Division by zero");
		return Ans;
	}
	Long_add_right(Ans, 0);
	Ans->sign = A->sign * B->sign;
	A_copy->sign = 1;
	B_zeros->sign = 1;
	if ((B->Size > A->Size) && (Minus(A, B, 0)->sign < 0))
		return Ans;
	for (i = 0; i < A->Size - B->Size; i++)
	{
		temp_A = temp_A->next;
		Long_add_right(B_zeros, 0);
	}
	while (B_zeros->head->data == 0)
	{
		div = 0;
		while (Minus(A_copy, B_zeros, 0)->sign > 0)
		{
			A_copy = Minus(A_copy, B_zeros, 0);
			div++;
		}
		Long_add_right(Ans, div);
		Long_remove_right(B_zeros);
	}
	div = 0;
	while (Minus(A_copy, B_zeros, 0)->sign > 0)
	{
		A_copy = Minus(A_copy, B_zeros, 0);
		div++;
	}
	Long_add_right(Ans, div);
	Long_remove_zero(Ans);
	Ans->sign = A->sign * B->sign;
	K = Minus(A, Product(B, Ans), 0);
	if (K->sign < 0)
	{
		if (B->sign * Ans->sign > 0)
			Ans->head->data--;
		else
			Ans->head->data++;
	}
	return Ans;
}