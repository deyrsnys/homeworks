/*
Поиск подстроки в строке
Колчин, 171
*/

#include <stdio.h>
#include <string.h>

int search_substring(char *substr, char *str);
 

void main(void)
{
	// Ïîèñê ïîäñòðîêè â ñòðîêå
	char substr[] = "ABdC";
	char str[] = "LNkdn3KN1kABdaQjdABCkdneqiaQ";
	

	printf("Intial string 1: %s\nInitial string 2 %s\n", substr, str);

	// Ïîëó÷àåì èíäåêñ íà÷àëà ñòðîêè
	int index = search_substring(substr,str);

	// Âûâîäèì ðåçóëüòàò ïîèñêà
	
	printf("\nResult: ");
	if (index >= 0)
	{
		for(int i = index; i < index + strlen(substr); ++i)
		{
			printf("%c",str[i]);
		}
	}
	else
	{
		printf(" there is no substring.");
	}
	printf("\nIndex: %d\n", index);

}



int search_substring(char *substr, char *str)
{
	//Àëãîðèòì êíóòà ìîððèñà ïðàòòà
	
	// Øàã 1. Îáúåäèíèì ñòðîêè â îäíó.
		// Íàéäåì äëèíû ñòðîê
	int len_substr = strlen(substr);	
	int len_str = strlen(str);
	
	char *main_str = (char*)malloc(len_substr+len_str);
	strcat(main_str,substr);
	strcat(main_str,str);
	
	// Øàã 2. Ñîçäàåì äèíàìè÷åñêèé ìàññèâ. Äëÿ ñîõðàíåíèÿ ðåçóëüòàòîâ
	// ïðåôèê ôóíêöèè.	
	int* pi = (int *)malloc(len_substr + len_str);
		// îáíóëÿåì âñå çíà÷åíèÿ â íåì
	for(int i = 0; i < len_substr + len_str; i++){
		pi[i] = 0;
	}

	// Øàã 3. Èñïîëüçóÿ ïðåôèê ôóíêöèþ, èùåì ïîäñòðîêó
	
	for(int i = 1; i < len_substr + len_str; i++){
		int j = pi[i-1];
		while (j > 0 && main_str[i] != main_str[j])
		{
			j = pi[j-1];
		}
		if (main_str[i] == main_str[j])
		{
			++j;
		}
		pi[i] = j;
		if (j == len_substr)
			return i - len_substr*2 + 1;
	}

	return -1; 
}
