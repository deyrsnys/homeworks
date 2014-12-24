#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spisok.h"

void print_menu()											//печать меню
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
	Spisok *spisok = Spisok_init();					//создаем список
	while (1)										//повторяем цикл всегда
	{
		char kommand_str[30];						//командная строка
		char kommand;								//команда из командной строки
		int value = 0;								//число для команд 'a' и 'r'
		int kod = 0;								//позиция ошибки при преобразовании value из string в int
		short bad_command = 0;						//правильно ли составлена команда
		print_menu();
		gets(kommand_str);							//получаем командную строку
		kommand = kommand_str[0];					//первый элемент строки используем как команду
		if ((kommand != 'a') && (kommand != 'r') && (kommand != 'p') && (kommand != 'q'))		//если команда не в списке 'a''r''p''q'
			bad_command = 1;															//она неправильная
		if (((kommand == 'p') || (kommand == 'q')) && (strlen(kommand_str) != 1))				//если после команд 'p' 'q' в строке ещё что-то, то срока не верна
			bad_command = 1;
		if (((kommand == 'a') || (kommand == 'r')) && (kommand_str[1] != ' '))				//если после 'a' 'r'  нет пробела, то команда не верна
			bad_command = 1;
		if (bad_command == 1)
		{
			printf("Incorrect command!\n");
			continue;								//идем на новый круг цикла, игнорируя код ниже
		}
		//если команда нормальная, то идем дальше
		switch (kommand)
		{
		case 'a':
		{
					value = get_value(&kommand_str, strlen(kommand_str), &kod);	//выделяем значение
					if ((kod != -1) || (strlen(kommand_str)<3))					//если есть ошибка (код равен -1 только при удачном переводе)
					{															//или значение не введено
						printf("Incorrect data!\n");							//сообщаем
						break;													//и выходим
					}
					Spisok_add(spisok, value);									//если все хорошо, то добавляем элемент
					break;
		}
		case 'r':
		{
					value = get_value(&kommand_str, strlen(kommand_str), &kod);	//выделяем значение
					if ((kod != -1) || (strlen(kommand_str)<3))
					{
						printf("Incorrect data!\n");
						break;
					}
					Spisok_remove(spisok, value);							//удаляем элемент
					break;
		}
		case 'p':
		{
					Spisok_print(spisok);			//печать
					break;
		}
		case 'q':									//если команда выхода
		{
														Spisok_clear(spisok);		//выход
														getch();					//задержка до нажатия любой кнопки
														exit(0);							//выход
		}
		}
	}
}