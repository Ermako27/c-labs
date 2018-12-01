#include <stdio.h>
#include "diffitems.h"

int diff_items(int *array, int *end) // количетсво различных элементов
{
    int *i = array;
    int item = *i;
    int count = 1;

    while (array < end)
    {
        if (item != *array)
        {
            //printf("item: %d array: %d\n", item, *array);
            item = *array;
            count += 1;
        }
        array++;
    }
    return count;
}