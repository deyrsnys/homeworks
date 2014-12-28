typedef struct node								 
{
	int data;									 
	struct node *next;							 
}node;

typedef struct Long_num							 
{
	node *head;									 
	node *tail;									 
	int sign;									 
	int Size;									 
}Long_num;

Long_num* Long_init();								 
char* Long_print(Long_num* number);					 
void Long_add_right(Long_num* number, int value);	 
void Long_add_left(Long_num* number, int value);	 
void Long_remove_zero(Long_num* number);			 
void Long_remove_right(Long_num* number);			 
void Long_clear(Long_num* number);					 

Long_num* Read_Long(char *c, int size, int* kod);	 
Long_num* Copy(Long_num* A);						 
