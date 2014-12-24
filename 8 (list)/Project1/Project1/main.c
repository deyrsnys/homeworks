/*
Односвязный список
Колчин, 171
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spisok.h"

void print_menu()											//ïå÷àòü ìåíþ
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
	Spisok *spisok = Spisok_init();					//ñîçäàåì ñïèñîê
	while (1)										//ïîâòîðÿåì öèêë âñåãäà
	{
		char kommand_str[30];						//êîìàíäíàÿ ñòðîêà
		char kommand;								//êîìàíäà èç êîìàíäíîé ñòðîêè
		int value = 0;								//÷èñëî äëÿ êîìàíä 'a' è 'r'
		int kod = 0;								//ïîçèöèÿ îøèáêè ïðè ïðåîáðàçîâàíèè value èç string â int
		short bad_command = 0;						//ïðàâèëüíî ëè ñîñòàâëåíà êîìàíäà
		print_menu();
		gets(kommand_str);							//ïîëó÷àåì êîìàíäíóþ ñòðîêó
		kommand = kommand_str[0];					//ïåðâûé ýëåìåíò ñòðîêè èñïîëüçóåì êàê êîìàíäó
		if ((kommand != 'a') && (kommand != 'r') && (kommand != 'p') && (kommand != 'q'))		//åñëè êîìàíäà íå â ñïèñêå 'a''r''p''q'
			bad_command = 1;															//îíà íåïðàâèëüíàÿ
		if (((kommand == 'p') || (kommand == 'q')) && (strlen(kommand_str) != 1))				//åñëè ïîñëå êîìàíä 'p' 'q' â ñòðîêå åù¸ ÷òî-òî, òî ñðîêà íå âåðíà
			bad_command = 1;
		if (((kommand == 'a') || (kommand == 'r')) && (kommand_str[1] != ' '))				//åñëè ïîñëå 'a' 'r'  íåò ïðîáåëà, òî êîìàíäà íå âåðíà
			bad_command = 1;
		if (bad_command == 1)
		{
			printf("Incorrect command!\n");
			continue;								//èäåì íà íîâûé êðóã öèêëà, èãíîðèðóÿ êîä íèæå
		}
		//åñëè êîìàíäà íîðìàëüíàÿ, òî èäåì äàëüøå
		switch (kommand)
		{
		case 'a':
		{
					value = get_value(&kommand_str, strlen(kommand_str), &kod);	//âûäåëÿåì çíà÷åíèå
					if ((kod != -1) || (strlen(kommand_str)<3))					//åñëè åñòü îøèáêà (êîä ðàâåí -1 òîëüêî ïðè óäà÷íîì ïåðåâîäå)
					{															//èëè çíà÷åíèå íå ââåäåíî
						printf("Incorrect data!\n");							//ñîîáùàåì
						break;													//è âûõîäèì
					}
					Spisok_add(spisok, value);									//åñëè âñå õîðîøî, òî äîáàâëÿåì ýëåìåíò
					break;
		}
		case 'r':
		{
					value = get_value(&kommand_str, strlen(kommand_str), &kod);	//âûäåëÿåì çíà÷åíèå
					if ((kod != -1) || (strlen(kommand_str)<3))
					{
						printf("Incorrect data!\n");
						break;
					}
					Spisok_remove(spisok, value);							//óäàëÿåì ýëåìåíò
					break;
		}
		case 'p':
		{
					Spisok_print(spisok);			//ïå÷àòü
					break;
		}
		case 'q':									//åñëè êîìàíäà âûõîäà
		{
														Spisok_clear(spisok);		//âûõîä
														getch();					//çàäåðæêà äî íàæàòèÿ ëþáîé êíîïêè
														exit(0);							//âûõîä
		}
		}
	}
}
