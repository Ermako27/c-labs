#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void print_text(int word_count, int m, char *data[m])
{
	for (int i = 0; i < word_count; i++)
	{
		printf("%s ", data[i]);
	}
}


void space_delete(char *data)
{
	char signs[7] = ",!?:;-.";
	int len = strlen(data);
	int k = 0;
	int c = 0;

	for (int i = 0; i < len; i++)
	{
		if (data[i-1] = ' ' && data[i] == ',' && data[i] != ' ')
		{
			data[i-1] = data[i];
			data[i] = ' ';
			break;
		}
	}
	//printf("data[len-1]: %c\n", data[len-1]);

	for (int i = 0; i < len; i++) // удаление лишних пробелов
	{
		if (data[i-k] == ' ' && data[i-k+1] == ' ')
		{
			//printf("i: %d i+1: %d\n",i ,i+1);
			for (int j = i - k; j < len; j++)
			{
				data[j] = data[j+1];
			}
			k++;
		}
	}
	if (data[0] == ' ' && data[1] != ' ') //удаление оставшегося пробела в начале 
	{
		for (int p = 0; p < len; p++) 
		{
			data[p] = data[p+1];
		}
	}
	for (int i = 0; i < len; i++) // удаление пробелов 
	{
		if (data[i] == ' ' && strchr(signs,data[i+1]) != NULL)
		{
			for (int j = i; j < len; j++)
			{
				data[j] = data[j+1];
			}
		}
	}
}

int word_count(char *data)
{
	int count = 0;

	int len = strlen(data);
	for (int i = 0; i < len; i++)
	{
		if (data[i] == ' ')
			count++;
	}
	count++;
	return count;
}

char** split(char *data,int word_count)
{
	int len = strlen(data);
	char signs[8] = ".,!?:;- ";
	int j = 0;
	int k = 0, p = 0;
	int flag = 0;
	//printf("%d\n", word_count);

	// выделение памяти
	char **words = calloc(word_count, sizeof(char*));

	for (int i = 0; i < word_count; i++)
	{
		words[i] = malloc(20 * sizeof(char));
	}
	
	// выделение слов

	for (int i = 0; i < len; i++)
	{	
		if (strchr(signs,data[i]) == NULL)
		{
			//printf("k: %d p: %d\n",k, p);
			words[k][p] = data[i];
			p++;
			flag = 0;
		}
		
		else if (flag == 0)
		{
			k++;
			p = 0;
			flag = 1;
		}	
	}
	
	return words;
}


void alpha_sort(int size, int m, char *data[m])
{
	char *tmp;
	data[0][0] = tolower(data[0][0]);
	char *lower = data[0];
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (strcmp(data[j], data[j+1]) > 0)
			{
				tmp = data[j];
				data[j] = data[j+1];
				data[j+1] = tmp;
			}
		}
	} 

	for (int i = 0; i < size; i++)
	{
		if (strcmp(data[i], lower) == 0)
		{
			data[i][0] = toupper(data[i][0]);
		}
	}
}

void len_sort(int size, int m, char *data[m])
{
	char *tmp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (strlen(data[j]) > strlen(data[j+1]))
			{
				tmp = data[j];
				data[j] = data[j+1];
				data[j+1] = tmp;
			}
		}
	} 
}

void word_alpha_sort(int size, int m, char *data[m])
{
	char tmp;
	data[0][0] = tolower(data[0][0]);
	char lower = data[0][0];
	int len;
	int first_len;

	for (int k = 0; k < size; k++)
	{
		len = strlen(data[k]);

		for (int i = 0; i < len - 1; i++)
		{
			for (int j = 0; j < len - i - 1; j++)
			{
				if (data[k][j] > data[k][j+1])
				{
					tmp = data[k][j];
					data[k][j] = data[k][j+1];
					data[k][j+1] = tmp;
				}
			}
		} 
	}

	first_len = strlen(data[0]);
	for (int i = 0; i < first_len; i++)
	{
		if (data[0][i] == lower)
		{
			data[0][i] = toupper(data[0][i]);
			break;
		}
	}
}





int main(void)
{
	char string[256];
	char *str;
	str = string;
	int len;
	int count;
	char **split_sentence1;
	char **split_sentence2;
	char **split_sentence3;


	printf("input ur string: ");
	fgets(str,256,stdin);


	space_delete(str); // удаление пробелов
    str[0] = toupper(str[0]); // первая буква заглавная
    len = strlen(str);
  //  printf("%d\n", len);

//    printf("last: %c|\n", str[len-1]);

    str[len-1] = '.'; // последний символ точка
	printf("GOST:%s\n\n", str);
	count = word_count(str);
//	printf("%d\n", count);

// сортировка слов по алфавиту
	printf("Alpha sort\n");
	split_sentence1 = split(str,count);
	alpha_sort(count,20,split_sentence1); 	
	print_text(count,20,split_sentence1);
	printf("\n------------------------------------\n");

// сортировка слов по длине 
	printf("Len sort\n");
	split_sentence2 = split(str,count);
	len_sort(count,20,split_sentence2);
	print_text(count,20,split_sentence2);
	printf("\n------------------------------------\n");


// сортировка букв в каждом слове

	printf("Word alpha sort\n");
	split_sentence3 = split(str,count);
	word_alpha_sort(count,20,split_sentence3);
	print_text(count,20,split_sentence3);
	printf("\n------------------------------------\n");


}