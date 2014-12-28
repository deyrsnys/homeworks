#include <stdio.h>
#include <stdlib.h>
#include "Long_num.h"

Long_num* Long_init()								 
{
	struct Long_num* number = (Long_num*)malloc(sizeof(Long_num));		 
	if (number == NULL)												 
	{
		printf("Not enough memory!\n");
		return NULL;
	}
	number->head = NULL;							 
	number->tail = NULL;							 
	number->sign = 1;								 
	number->Size = 0;								 
	return number;
}

char* Long_print(Long_num* number)					 
{
	char *Res;										 
	int i;											 
	if (number->sign == -1)							 
	{
		Res = (char*)malloc(sizeof(char)*number->Size + 2);
		i = number->Size;
	}
	else
	{
		Res = (char*)malloc(sizeof(char)*number->Size + 1);
		i = number->Size - 1;
	}
	Res[i + 1] = '\0';								 
	node *temp = number->head;						 
	if (number->Size == 0)
	{
		return "Number is empty\n";
	}
	while (temp != NULL)							 
	{
		Res[i] = (char)(temp->data + '0');
		i--;
		temp = temp->next;							 
	}
	if (number->sign == -1)
		Res[0] = '-';
	return Res;
}
void Long_add_right(Long_num * number, int value)	 
{
	node *n = (node*)malloc(sizeof(node));			 
	if (n == NULL)
	{
		printf("Not enough memory!\n");
		return;
	}
	n->data = value;								 
	n->next = number->head;							 
	number->head = n;								 
	number->Size++;									 
	if (number->Size == 1)							 
		number->tail = number->head;				 
}
void Long_add_left(Long_num* number, int value)		 
{
	node *n = (node*)malloc(sizeof(node));			 
	if (n == NULL)
	{
		printf("Not enough memory!\n");
		return;
	}
	n->data = value;								 
	n->next = NULL;
	if (number->Size != 0)							 
		number->tail->next = n;						 
	number->tail = n;								 
	number->Size++;									 
	if (number->Size == 1)							 
		number->head = number->tail;				 
}
void Long_remove_zero(Long_num* number)				 
{
	node *temp = number->head;						 
	if (number->Size < 2)							 
		return;
	if (number->tail->data == 0)					 
	{
		while (temp->next != number->tail)			 
			temp = temp->next;
		free(number->tail);							 
		temp->next = NULL;
		number->Size--;
		number->tail = temp;						 
		Long_remove_zero(number);					 
	}
	number->tail->next = NULL;						 
}
void Long_remove_right(Long_num* number)			 
{
	node* temp = number->head;						 
	number->head = number->head->next;				 
	number->Size--;									 
	free(temp);										 
}
void Long_clear(Long_num* number)					 
{
	node *temp = number->head;						 
	while (number->head != NULL)
	{
		temp = number->head;						 
		number->head = number->head->next;			 
		free(temp);									 
	}
	free(number);									 
}

Long_num* Read_Long(char *c, int size, int* kod)	 
{
	Long_num* Ans = Long_init();					 
	int i = 0;										 
	*kod = -1;
	if (size == 0)									 
	{
		Long_clear(Ans);							 
		*kod = 1;									 
		return NULL;
	}
	if (c[0] == '-')								 
	{
		if (size == 1)								 
		{
			Long_clear(Ans);						 
			*kod = 1;								 
			return NULL;
		}
		Ans->sign = -1;								 
		i++;										 
	}
	while (i < size)								 
	{
		if ((c[i]<'0') || (c[i]>'9'))				 
		{
			*kod = i;								 
			return Long_init();						 
		}
		Long_add_right(Ans, c[i] - '0');			 
		i++;
	}
	Long_remove_zero(Ans);							 
	return Ans;
}

Long_num* Copy(Long_num* A)						 
{
	Long_num* Res = Long_init();				 
	node* temp_A = A->head;						 
	Res->sign = A->sign;						 
	while (temp_A != NULL)
	{
		Long_add_left(Res, temp_A->data);		 
		temp_A = temp_A->next;
	}
	return Res;									 
}