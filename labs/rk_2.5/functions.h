#ifndef __FUNCTIONS__H__

#define __FUNCTIONS__H__

void space(char *text);

void reverse(char *t1,char *t2, FILE *f);

int  my_getdelim(char **lineptr, size_t *n, int delim, FILE *stream, int count);

size_t getdelim(char **lineptr, size_t *n, int delimiter, FILE *stream);


#endif
