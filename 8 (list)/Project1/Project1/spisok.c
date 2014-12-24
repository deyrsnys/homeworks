#include <stdio.h>
#include <stdlib.h>
#include "spisok.h"

Spisok* Spisok_init()			
//инициализация списка
{
	struct Spisok* spisok = (Spisok*)malloc(sizeof(Spisok));		//выделяем память и задаем начальные значения
	if (spisok == NULL)												//NULL, если память не выделена
	{
		printf("Not enough memory!\n");
		return NULL;
	}
	spisok->head = NULL;							//создаем пустой список
	spisok->Size = 0;								//
	return spisok;
}

void Spisok_print(Spisok * S)						//печать списка
{
	node *temp = S->head;							//temp - бегунок по списку, начинаем с вершины
	int i = 0;										//счетчик
	printf("List with %d elements.\n", S->Size);		//вывод количества элементов
	while (temp != NULL)								//пока не дошли до конца списка
	{
		printf("%d", temp->data);					//выводим значение
		if (i < S->Size - 1)						//если элемент не последний
			printf(", ");							//то выводим запятую
		else printf("\n");							//иначе перевод строки
		i++;
		temp = temp->next;							//переход к следующему элементу
	}
}
void Spisok_add(Spisok * S, int value)				//добавить элемент
{
	node *n = (node*)malloc(sizeof(node));			//создаем новый элемент списка
	if (n == NULL)
	{
		printf("Not enough memory!\n");
		return NULL;
	}
	n->data = value;								//присваиваем ему значение
	n->next = S->head;								//делаем указатель от него к старой вершине
	S->head = n;									//запоминаем этот элемент, как новую вершину
	S->Size++;										//увеличиваем размер
}
void Spisok_remove(Spisok * S, int value)			//удалить элемент
{
	node *temp = S->head;							//бегунок по списку, начинаем с вершины
	node *prev = NULL;								//элемент беред бегунком temp
	int i = 0;
	if (temp->data == value)						//если нужный нам элемент в самом начале
	{
		S->head = temp->next;						//сдвигаем вершину списка
		free(temp);									//удаляем старую вершину списка
		S->Size--;									//уменьшаем размер
		return;										//выходим
	}
	while (temp != NULL)								//пока не дошли до конца
	{
		if (temp->data == value)					//если нашли нужный элемент
		{
			prev->next = temp->next;				//меняем последовательность элементов, ставим указатель с элемента перед бегунком, на элемент после бугунка (пример 3->1->2 станет 3->2)
			free(temp);								//удаляем найденный элемент
			S->Size--;								//уменьшаем размер
			break;									//выходим
		}
		prev = temp;
		temp = temp->next;
	}
}
void Spisok_clear(Spisok * S)						//очистить список
{
	node *temp = S->head;							//бегунок по списку, начинаем с вершины
	node *prev = NULL;								//элемент беред бегунком temp
	printf("Start clear list....\n");
	while (temp != NULL)
	{
		prev = temp;								//запоминаем предыдущий
		temp = temp->next;							//сдвигаем бегунок
		free(prev);									//удаляем предыдущий
	}
	printf("All elements were deleted.\n");
	free(S);										//удаляем заголовок списка (информация о вершине и размере)
	printf("List deleted.");
}

int get_value(char *c, int size, int* kod)			//выделяет параметр 'a' и 'r' (переводит из строки в int)
{
	int Res = 0;									//результат перевода
	int i;											//позиция в строке
	int sign = 1;									//знак числа
	int start = 2;									//с какой позиции в строке начинается число
	if (c[2] == '-')								//если 1 знак в числе "-"
	{
		sign = -1;									//то знак числа отрицательный
		start++;									//сдвигаем начало числа
	}
	*kod = (-1);									//код ошибки (все хорошо)
	for (i = start; i<size; i++)
	{
		if ((c[i]<'0') || (c[i]>'9'))					//если не цифра
		{
			*kod = i;								//ошибка на этой позиции
			return 0;								//вернем 0, из-за неудачного перевода
		}
		Res = Res * 10 + (c[i] - '0');					//если цифра, то умножаем уже полученный результат на 10 и прибавляем эту цифру
	}
	return Res*sign;								//умножаем на знак
}