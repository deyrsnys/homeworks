typedef struct node								
{
	int data;									
	struct node *next;							
}node;

typedef struct Spisok							
{
	node *head;									
	int Size;									
}Spisok;

Spisok* Spisok_init();							
void Spisok_print(Spisok * S);					
void Spisok_add(Spisok * S, int value);			
void Spisok_remove(Spisok * S, int value);		
void Spisok_clear(Spisok * S);					

int get_value(char *c, int size, int* kod);	