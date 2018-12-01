#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT_SIZE 128

int  my_getdelim(char **lineptr, size_t *n, int delim, FILE *stream, int count)
{
  printf("delim: %c", delim);
  char buffer[10];
  int len_buf;
  int indx = 0;
  //int indx_over = 0;
  int flag = 0;
  char c;
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


  printf("count: %d\n", count);

  rewind(stream);
  fgets(middle,count+1,stream);

  printf("\nmiddle%s\n", middle);
  


  while (fgets(buffer,10,stream))
  {
    len_buf = strlen(buffer);

    printf("\nbuffer: %s\n", buffer);
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
        // for (int j = i+1; j < len_buf; j++)
        // {
        //   over_buff[indx_over++] = buffer[j];
        //   //printf("%c", buffer[j]);
        // }
        //printf("line: %s\n",*lineptr);
        //printf("over: %s\n", over);
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

int main(void)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    int read;
    int count = 0;

   fp = fopen("test2.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

   while ((read = my_getdelim(&line, &len, '\n', fp, count)) != -1) {
   //while ((read = getdelim(&line, &len, '\n', fp)) != -1) {
        printf("Retrieved line of length %d :", read);
        printf("%s\n", line);
        // printf("over: %s\n", over_buff);
        printf("--------------------\n");
        count += read;
    }

   free(line);
   exit(EXIT_SUCCESS);
}




      // if (len_over_buff != 0) // считываение остатка буфера если он есть, 
      // {
      //   for (int i = 0; i < len_over_buff; i++)
      //   {
      //     (*lineptr)[indx++] = over_buff[i];
      //     if ((int)over_buff[i] == delim)
      //     {
      //       for (int j = 0; j < indx, j++)
      //       {
      //         for (int p = 0; p < len_buf - k; k++)
      //         {
      //           over_buff[p] = over_buff[p+1];
      //         }
      //         k++
      //       }
      //     }
      //   }
      // }


   // printf("len: %d\n", len_buf);