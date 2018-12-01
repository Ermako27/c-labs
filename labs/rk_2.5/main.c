#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

int main(void)
{
	char c;
	FILE *f, *f2;
	int bl;
	int p = 0;
	f = fopen("test.txt", "r");
	f2 = fopen("result.txt", "wb");
	char *text = malloc(32*sizeof(char));
	char *t1 = text;
	char text1[100];
	char *t2 = text1;
	char buff[30]; // буфер

	char *line = NULL;
	size_t len = 0;
	char read;






	if (f == NULL || f2 == NULL)
	{
		printf("Cant open file!\n");
		return 0;
	}

	if (fscanf(f, "%c", &c) != 1)
	{
		printf("Empty file!\n");
		return 0;
	}

	rewind(f);




	// while(fgets(buff,31, f)) // чтение из файла
	// {
	// 	bl = strlen(buff);	
	// 	for (int i = 0; i < bl; i++)
	// 	{
	// 		t1[p] = buff[i];
	// 		p++;
	// 	}
	// }
	while ((read = getdelim(&line, &len, '\n', f)) != -1)
	{
		bl = strlen(line);
		for (int i = 0; i < bl; i++)
		{
			t1[p] = line[i];
			p++;
		}
	}


	space(t1); // удаление пробелов

	reverse(t1,t2,f2); // перестановка слов


	return 0;
	

}