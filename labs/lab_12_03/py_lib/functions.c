#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define INCORRECT -1
#define OK 1

int data_copy(int *data1, int **data2, int n, int key) 
{
    if(n <= 0)
        return INCORRECT;
    
    *data2 = calloc(n*2, sizeof(int));
    int count = 0;
    
    int *begin = *data2;
    
    for (int i = 0; i<n; i++)
    {
        **data2 = *data1;
        count++;
        (*data2)++;
        if (*data1 % 2 == 0)
        {
            **data2 = key;
            count++;
            (*data2)++;
        }
        data1++;
    }
    
    *data2 = begin;
    
    return count;
}


int simple_numbers(int **data, int n) 
{    
    if (n <= 0)
        return INCORRECT;
    *data = malloc(n * sizeof(int));
    
    int i = 0;
    int k = 0;
    int flag = 0;
    while(k < n)
    {
        if (i == 0)
        {
            (*data)[k] = 1;
            k++;
            i++;
        }
        else
        {
            flag = 1;
            for (int j = 2; j < i; j++)
            {
                if ((i+1)%j == 0)
                {
                    i++;
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                i++;
                (*data)[k] = i;
                k++;
            }
        }
    }  
    return OK;
}
