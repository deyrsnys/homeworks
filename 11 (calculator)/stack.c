#include <stdio.h>
#include <stdlib.h>
#include "Long_num.h"
#include "Math_operations.h"
#include "stack.h"

Stack* Stack_init()														 
{
	Stack* New_Stack = (Stack*)malloc(sizeof(Stack));
	if (New_Stack == NULL)												 
	{
		printf("Not enough memory!\n");
		return NULL;
	}
	New_Stack->head = NULL;
	New_Stack->Size = 0;
	return New_Stack;
}
void Stack_push_top(Stack* A, Long_num* value)							 
{
	stack_node *n = (stack_node*)malloc(sizeof(stack_node));			 
	if (n == NULL)
	{
		printf("Not enough memory!\n");
		return;
	}
	n->data = value;							 
	n->next = A->head;							 
	A->head = n;								 
	A->Size++;									 
}
Long_num* Stack_pop_top(Stack* A)				 
{
	stack_node* temp = A->head;					 
	if (A->Size >= 1)							 
	{
		A->head = A->head->next;				 
		A->Size--;								 
	}											 
	return temp->data;
}
void Stack_print(Stack* A)						 
{
	stack_node* temp = A->head;					 
	char* number;								 
	printf("[");								 
	while (temp != NULL)						 
	{
		number = Long_print(temp->data);		 
		printf(number);							 
		if (temp->next != NULL)					 
			printf("; ");						 
		temp = temp->next;						 
	}
	printf("]");								 
	return;
}
void Stack_clear(Stack* A)						 
{
	stack_node* temp = A->head;					 
	while (A->head != NULL)						 
	{
		temp = A->head;							 
		Long_clear(A->head->data);				 
		A->head = A->head->next;				 
		free(temp);								 
	}
	free(A);									 
	return;
}