#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spisok.h"

void print_menu()											 
{
	printf("########### MENU ###########\n");
	printf("# a <int> - add new number #\n");
	printf("# r <int> - remove number  #\n");
	printf("# p - print list           #\n");
	printf("# q - quit                 #\n");
	printf("############################\n");
	printf("->");
	return;
}

void main()
{
	Spisok *spisok = Spisok_init();					 
	while (1)										 
	{
		char kommand_str[30];						 
		char kommand;								 
		int value = 0;								 
		int kod = 0;								 
		short bad_command = 0;						 
		print_menu();
		gets(kommand_str);							 
		kommand = kommand_str[0];					 
		if ((kommand != 'a') && (kommand != 'r') && (kommand != 'p') && (kommand != 'q'))		 
			bad_command = 1;															 
		if (((kommand == 'p') || (kommand == 'q')) && (strlen(kommand_str) != 1))				 
			bad_command = 1;
		if (((kommand == 'a') || (kommand == 'r')) && (kommand_str[1] != ' '))				 
			bad_command = 1;
		if (bad_command == 1)
		{
			printf("Incorrect command!\n");
			continue;								 
		}
		 
		switch (kommand)
		{
		case 'a':
		{
					value = get_value(&kommand_str, strlen(kommand_str), &kod);	 
					if ((kod != -1) || (strlen(kommand_str)<3))					 
					{															 
						printf("Incorrect data!\n");							 
						break;													 
					}
					Spisok_add(spisok, value);									 
					break;
		}
		case 'r':
		{
					value = get_value(&kommand_str, strlen(kommand_str), &kod);	 
					if ((kod != -1) || (strlen(kommand_str)<3))
					{
						printf("Incorrect data!\n");
						break;
					}
					Spisok_remove(spisok, value);							 
					break;
		}
		case 'p':
		{
					Spisok_print(spisok);			 
					break;
		}
		case 'q':									 
		{
														Spisok_clear(spisok);		 
														getch();					 
														exit(0);							 
		}
		}
	}
}