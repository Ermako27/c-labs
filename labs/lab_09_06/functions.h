#ifndef __FUNCTIONS__H__

#define __FUNCTIONS__H__

int  my_getdelim(char **lineptr, size_t *n, int delim, FILE *stream, int count);

void replace(char *str,char *a,char *b,char buffer[]);

size_t getdelim(char **lineptr, size_t *n, int delimiter, FILE *stream);

#endif
