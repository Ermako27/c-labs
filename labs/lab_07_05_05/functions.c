#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include "functions.h"

#define OK 0
#define ALLOCERR 1
#define SORTERR 2


#define SWAP(a, b, size)                                                      \
      do                                                                              \
        {                                                                              \
          size_t __size = (size);                                                      \
          char *__a = (a), *__b = (b);                                              \
          do                                                                      \
            {                                                                      \
              char __tmp = *__a;                                                      \
              *__a++ = *__b;                                                      \
              *__b++ = __tmp;                                                      \
            } while (--__size > 0);                                                      \
        } while (0)


unsigned long long tick(void)
{
 unsigned long long d;
 __asm__ __volatile__ ("rdtsc" : "=A" (d) );
 return d;
}


void print_mass(float a[], int size) // функция печати массива
{
    for (int i = 0; i < size; i++)
    {
        if (fabs(a[i] - (int)a[i]) > 0)
            printf("%.3f ", a[i]);
        else if ((a[i] - (int)a[i]) == 0)
            printf("%d ", (int)a[i]);
        //printf("\n");
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

int filtr_count(FILE *f, float **data, int *n, float *s)
{
    int count = 0;
    float num;
    float sum = 0.0;
    *s = 0.0;
    while (fscanf(f, "%f", &num) == 1)
        sum += num;
    rewind(f);
    *s = sum;
    while (fscanf(f, "%f", &num) == 1)
    {
        sum -= num;
        if (num > sum)
        {
            count += 1;
            //printf("%f", num);
        }
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
            return ALLOCERR;
    }
    return OK;
}

void array_create_f(float* data, FILE *f, float sum)
{
    float num = 0.0;
    float* array = data;
    while (fscanf(f, "%f", &num) == 1)
    {
        sum -= num;
        if (num > sum)
        {
            *array = num;
            array++;
        }
    }
}

int compare(const void* p, const void* q)
{
   const float *a = p;
   const float *b = q;
    return *a - *b;
}

void sort(void *pbase, size_t total, size_t size, int (*compare)(const void*, const void*))
{
    char *b = pbase;
    char *lo = b;
    char *hi = lo + total * size;
    char *new_el, *loc;

    for (lo = lo + size; lo < hi; lo += size)
    {
        new_el = lo;
        //loc = lo - size;
        for (loc = lo - size; loc >= b; loc -= size)
        {
            if (compare(loc,new_el)> 0)
            {
                SWAP(loc,new_el,size);

            }
            new_el -= size;
        }
    }
}

