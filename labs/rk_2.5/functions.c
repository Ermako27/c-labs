#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


#define DEFAULT_SIZE 128

int  my_getdelim(char **lineptr, size_t *n, int delim, FILE *stream, int count)
{
  char buffer[10];
  int len_buf;
  int indx = 0;
  //int indx_over = 0;
  int flag = 0;
  char middle[100];

  if (lineptr == NULL || n == NULL || stream == NULL)
      return -1;
  if (*lineptr == NULL) // memory allocation first time
  {
    *lineptr = malloc(DEFAULT_SIZE);
    if (*lineptr == NULL)
      return -1;
    *n = DEFAULT_SIZE;
  }

  //printf("%d\n", count);
  rewind(stream);
  fgets(middle,count+1,stream);
 // printf("middle%s\n", middle);
  while (fgets(buffer,10,stream))
  {
    len_buf = strlen(buffer);

  //  printf("buffer: %s\n", buffer);
    if (indx > *n)
    {
     *lineptr = realloc(*lineptr, *n + DEFAULT_SIZE);
      if (*lineptr = NULL)
        return -1;
      *n += DEFAULT_SIZE;
    }

   // printf("len: %d\n", len_buf);

    for (int i = 0; i < len_buf; i++)
    {
      (*lineptr)[indx++] = buffer[i];
      if ((int)buffer[i] == delim)
      {
        flag = 1;
        break;
      }
    }
    if (flag == 1)
    {
      break;
    }
  }

  if (indx >= *n)
  {
       *lineptr = realloc (*lineptr, *n + DEFAULT_SIZE);
       if (*lineptr == NULL)
            return -1;
       *n += DEFAULT_SIZE;
    }

   (*lineptr)[indx++] = 0;

   return ((indx - 1) == 0) ? -1 : indx - 1;

}

void space(char *text)
{
	int len;
	int k = 0;

	len = strlen(text);
	for (int i = 0; i < len; i++)
	{
		if ((text[i-k] == ' ' && text[i-k+1] == ' '))
		{
			for (int j = i - k; j < len; j++)
			{
				text[j] = text[j+1];
			}
			k++;
		}

		if ((text[i-k-1] == '\n' && text[i-k] == ' ' && text[i-k+1] != ' '))
		{
			for (int j = i - k; j < len; j++)
			{
				text[j] = text[j+1];
			}
			k++;
		}
	}

	if (text[0] == ' ' && text[1] != ' ') //удаление оставшегося пробела в начале 
	{
		for (int p = 0; p < len; p++) 
		{
			text[p] = text[p+1];
		}
	}

	int r = strlen(text);
	//printf("zxcv%c\n", text[r-1]);
	if (text[r-1] == ' ')
		text[r-1] = '\0';
}


void reverse(char *t1,char *t2, FILE *f)
{
	int len;
	len = strlen(t1);

	for (int i = 0; i < len; i++)
	{
		printf("%c", t1[i]);
	}

	for (int i = 0; i < len+1; i++)
	{
		t2[i] = t1[len-i];
	}

	printf("\n");
	printf("\n");
	t2[len] = t1[0];

	for (int i = 0; i < len+1; i++)
	{
		printf("%c", t2[i]);
	}

	printf("\n");


}