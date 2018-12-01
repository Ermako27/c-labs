#include <stdio.h>
#include "sort.h"

void sort(int *array,int *s_array, int *end) // сортировка для последующего подсчета различных элементов
{
   // printf("array: %d, end: %d ", *array, *end);
    //while (array < end && (*array) > 0)
    while (array < end)
    {
        int *j = s_array; // указатель для второго цикла т.к. первый меняется
        //printf("iteration\n");
        //while (j < end -1 && (*j > 0))
        while (j < end -1)
        {
            //printf("J: %d J+1: %d\n", *j, *(j+1));
            if (*j > *(j+1))
            {
                //printf("swap\n");
                int t = *j;
                *j = *(j+1);
                *(j+1) = t;

            }
            j++;
        }
        array++;
    }
}