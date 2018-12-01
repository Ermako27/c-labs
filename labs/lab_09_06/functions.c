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



void replace(char *str,char *a,char *b,char buffer[])
{
    int i,j,pos=0;
    for(i=0;str[i];i++)
    {
        for(j=0;str[i+j]&&a[j];j++)   //начинается ли с i-ой позиции строка a
        {
            if(str[i+j]!=a[j]) 
                break;
        }
        if(!a[j])  //если a[j]=0, то мы дошли до конца строки a
        {
            i+=j-1;  //в j у нас длина стоки a, которую мы перепрыгиваем
            for(j=0;b[j];j++) 
                buffer[pos++]=b[j];  //на место стоки a ставим строку b
        }
        else
        {
            buffer[pos++]=str[i];   //просто копируем символ
        }
        buffer[pos]='\0';  //ставим конец строки
    }
    strcpy(str,buffer);  //копируем в первоначальную строку
}