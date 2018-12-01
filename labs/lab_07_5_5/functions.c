#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

#define OK 0
#define ALLOCERR 1
#define SORTERR 2

void print_mass(float a[], int size) // функция печати массива
{
    for (int i = 0; i < size; i++)
    {
        if ((a[i] - (int)a[i]) > 0)
            printf("%.3f ", a[i]);
        else if ((a[i] - (int)a[i]) == 0)
            printf("%d ", (int)a[i]);
    }
    printf("\n");
}

int array_count(FILE *f, float **data, int *n)
{
    int count = 0;
    float num;
    while (fscanf(f,"%f", &num) == 1)
        count += 1;
    *data = malloc(count * sizeof(float));
    if (*data)
    {
        *n = count;
        return OK;
    }
    else
    {
        return ALLOCERR;
    }
    return OK;
}

void array_create(float* data, FILE *f)
{
    float num = 0.0;
    float* array = data;
    while (fscanf(f, "%f", &num) == 1)
    {
        *array = num;
        array++;

    }
}
int filtr_count(FILE *f, float **data, int *n)
{
    int count = 0;
    float num;
    float sum = 0.0;
    while (fscanf(f, "%f", &num) == 1)
    {
        if (num > sum)
        {
            count += 1;
            //printf("%d", count);
        }
        sum += num;
    }
    if (count)
    {
        *data = malloc(count * sizeof(float));
        if (*data)
        {
            *n = count;
            return OK;
        }
        else
        {
            return ALLOCERR;
        }
    }
    return OK;
}
void array_create_f(float* data, FILE *f)
{
    float num = 0.0;
    float sum = 0.0;
    float* array = data;
    while (fscanf(f, "%f", &num) == 1)
    {
        if (num > sum)
        {
            *array = num;
            array++;
        }
        sum += num;
    }
}

int sort(float* data, int n)
{
    int k, j;
    for (j = 0; j < n - 1; j++)
    {
        int f = 0;
        for (k = j + 1; k < n; k++)
        {
            if (*(data + j) > *(data + k ))
            {
                float temp = *(data + j);
                *(data + j) = *(data + k);
                *(data + k) = temp;
                f = 1;
            }
        }
        if (f == 0)
        {
            return OK;
        }

    }
    return OK;
}
