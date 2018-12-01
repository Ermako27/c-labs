#include <stdio.h>
#include "readfile.h"
#define OK 1
#define OVERFLOW -1



int read_file(FILE *f, int* pb, int *size) // запись чисел из файла в массив
{
    int* pcur = pb;
	if (size != NULL) // предотвращает  segmentation fault
        *size = 0;
    int num;
    while (fscanf(f, "%d", &num) == 1)
    {
        if (*size < 100)
        {
            *pcur = num;
            pcur++;
            *size += 1; // размер массива
        }
        else
            return OVERFLOW;
    }
    return OK;
}