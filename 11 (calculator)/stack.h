typedef struct stack_node						 
{
	Long_num* data;								 
	struct stack_node *next;					 
}stack_node;

typedef struct Stack							 
{
	stack_node *head;							 
	int Size;									 
}Stack;

Stack* Stack_init();							 
void Stack_push_top(Stack* A, Long_num* value);	 
Long_num* Stack_pop_top(Stack* A);				 
void Stack_print(Stack* A);						 
void Stack_clear(Stack* A);						 
