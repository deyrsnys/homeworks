typedef struct node								//€чейка списка
{
	int data;									//данные
	struct node *next;							//указатель на следующую €чейку
}node;

typedef struct Spisok							//заголовок списка (информаци€ о вершине и размере)
{
	node *head;									//вершина списка
	int Size;									//его размер
}Spisok;

Spisok* Spisok_init();							//инициализаци€ списка
void Spisok_print(Spisok * S);					//печать списка
void Spisok_add(Spisok * S, int value);			//добавить элемент
void Spisok_remove(Spisok * S, int value);		//удалить элемент
void Spisok_clear(Spisok * S);					//очистить список

int get_value(char *c, int size, int* kod);		//выдел€ет параметр 'a' и 'r'