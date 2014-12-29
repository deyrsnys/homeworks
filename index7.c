/*
Поиск подстроки в строке
Колчин, 171
*/
#include <stdio.h>
#include <string.h>

int search_substring(char *substr, char *str);


void main(void)
{
	// Поиск подстроки в строке
	char substr[] = "aa";
	char str[] = "aaaaa";


	printf("Intial string 1: %s\nInitial string 2 %s\n", substr, str);

	// Получаем индекс начала строки
	int index = search_substring(substr, str);

	// Выводим результат поиска

	printf("\nResult: %d", index);


}


int search_substring(char *substr, char *str)
{
	int len_substr = strlen(substr);
	int len_str = strlen(str);

	int counter = 0;
	int j = 0;
	int k = 0;
	for (int i = 0; i < len_str; ++i)
	{
		if (str[i] == substr[j])
		{
			if (j == 0)
			{
				k = i;
			}
			j++;
		}
		else
		{
			j = 0;
		}

		if (j == len_substr)
		{
			j = 0;
			counter++;
			i = k;
		}
	}
	return counter;
}

/*
//Алгоритм кнута морриса пратта. Не работает.

// Шаг 1. Объединим строки в одну.
// Найдем длины строк
int len_substr = strlen(substr);
int len_str = strlen(str);

char *main_str = (char*)malloc(len_substr+len_str);
strcat(main_str,substr);
strcat(main_str,str);

// Шаг 2. Создаем динамический массив. Для сохранения результатов
// префик функции.
int* pi = (int *)malloc(len_substr + len_str);
// обнуляем все значения в нем
for(int i = 0; i < len_substr + len_str; i++){
pi[i] = 0;
}

// Шаг 3. Используя префик функцию, ищем подстроку
int counter = 0;	// Заводим счетчик;
for(int i = 1; i < len_substr + len_str; i++){
int j = pi[i-1];

while ((j > 0 && main_str[i] != main_str[j]) || j >= len_substr)
{
j = pi[j-1];
}
if (main_str[i] == main_str[j])
{
++j;
}
pi[i] = j;
if (j == len_substr)
{
counter++;					// нашли подстроку, увеличили счетчик на 1
//return i - len_substr*2 + 1;
}

}

return counter;					// Вернули количество вхождений подстроки в строку 
*/
