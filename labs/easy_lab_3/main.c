#include <stdio.h>
#include <stdarg.h>

#define ZERO_ARGUMENTS -1

int word_count(FILE *f)
{
	int counter = 0;
	char ch;
	while (fscanf(f,"%c", &ch) == 1)
	{
		if (ch == ' ' || ch == '\n')
		{	
			counter++;
		}
	}
	return counter;

}



int secret_files(int count, ...)
{
	if (count == 0)
	{
		printf("Zero arguments!!!\n");
		return ZERO_ARGUMENTS;
	}
	int sum = 0;
	FILE *f;
	va_list argptr;

	va_start(argptr, count);
	for (;count;count--)
	{
		f = va_arg(argptr, FILE*);
		sum += word_count(f);
	}
	va_end(argptr);

	return sum;
}




int main(void)
{
	int count_of_words;

	FILE *f1;
	FILE *f2;
	FILE *f3;
	FILE *f4;


	f1 = fopen("test1.txt", "r");
	f2 = fopen("test2.txt", "r");
	f3 = fopen("test3.txt", "r");
	f4 = fopen("test4.txt", "r");


	count_of_words = secret_files(4,f1,f2,f3,f4);
	if (count_of_words == ZERO_ARGUMENTS)
		return 0;
	else
		printf("count of words in files: %d\n", count_of_words);
	return 0;
}