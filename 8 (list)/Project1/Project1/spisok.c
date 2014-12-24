#include <stdio.h>
#include <stdlib.h>
#include "spisok.h"

Spisok* Spisok_init()			
//������������� ������
{
	struct Spisok* spisok = (Spisok*)malloc(sizeof(Spisok));		//�������� ������ � ������ ��������� ��������
	if (spisok == NULL)												//NULL, ���� ������ �� ��������
	{
		printf("Not enough memory!\n");
		return NULL;
	}
	spisok->head = NULL;							//������� ������ ������
	spisok->Size = 0;								//
	return spisok;
}

void Spisok_print(Spisok * S)						//������ ������
{
	node *temp = S->head;							//temp - ������� �� ������, �������� � �������
	int i = 0;										//�������
	printf("List with %d elements.\n", S->Size);		//����� ���������� ���������
	while (temp != NULL)								//���� �� ����� �� ����� ������
	{
		printf("%d", temp->data);					//������� ��������
		if (i < S->Size - 1)						//���� ������� �� ���������
			printf(", ");							//�� ������� �������
		else printf("\n");							//����� ������� ������
		i++;
		temp = temp->next;							//������� � ���������� ��������
	}
}
void Spisok_add(Spisok * S, int value)				//�������� �������
{
	node *n = (node*)malloc(sizeof(node));			//������� ����� ������� ������
	if (n == NULL)
	{
		printf("Not enough memory!\n");
		return NULL;
	}
	n->data = value;								//����������� ��� ��������
	n->next = S->head;								//������ ��������� �� ���� � ������ �������
	S->head = n;									//���������� ���� �������, ��� ����� �������
	S->Size++;										//����������� ������
}
void Spisok_remove(Spisok * S, int value)			//������� �������
{
	node *temp = S->head;							//������� �� ������, �������� � �������
	node *prev = NULL;								//������� ����� �������� temp
	int i = 0;
	if (temp->data == value)						//���� ������ ��� ������� � ����� ������
	{
		S->head = temp->next;						//�������� ������� ������
		free(temp);									//������� ������ ������� ������
		S->Size--;									//��������� ������
		return;										//�������
	}
	while (temp != NULL)								//���� �� ����� �� �����
	{
		if (temp->data == value)					//���� ����� ������ �������
		{
			prev->next = temp->next;				//������ ������������������ ���������, ������ ��������� � �������� ����� ��������, �� ������� ����� ������� (������ 3->1->2 ������ 3->2)
			free(temp);								//������� ��������� �������
			S->Size--;								//��������� ������
			break;									//�������
		}
		prev = temp;
		temp = temp->next;
	}
}
void Spisok_clear(Spisok * S)						//�������� ������
{
	node *temp = S->head;							//������� �� ������, �������� � �������
	node *prev = NULL;								//������� ����� �������� temp
	printf("Start clear list....\n");
	while (temp != NULL)
	{
		prev = temp;								//���������� ����������
		temp = temp->next;							//�������� �������
		free(prev);									//������� ����������
	}
	printf("All elements were deleted.\n");
	free(S);										//������� ��������� ������ (���������� � ������� � �������)
	printf("List deleted.");
}

int get_value(char *c, int size, int* kod)			//�������� �������� 'a' � 'r' (��������� �� ������ � int)
{
	int Res = 0;									//��������� ��������
	int i;											//������� � ������
	int sign = 1;									//���� �����
	int start = 2;									//� ����� ������� � ������ ���������� �����
	if (c[2] == '-')								//���� 1 ���� � ����� "-"
	{
		sign = -1;									//�� ���� ����� �������������
		start++;									//�������� ������ �����
	}
	*kod = (-1);									//��� ������ (��� ������)
	for (i = start; i<size; i++)
	{
		if ((c[i]<'0') || (c[i]>'9'))					//���� �� �����
		{
			*kod = i;								//������ �� ���� �������
			return 0;								//������ 0, ��-�� ���������� ��������
		}
		Res = Res * 10 + (c[i] - '0');					//���� �����, �� �������� ��� ���������� ��������� �� 10 � ���������� ��� �����
	}
	return Res*sign;								//�������� �� ����
}