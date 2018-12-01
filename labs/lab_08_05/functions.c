#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 0
#define INCORRECT -1
#define UNEQUAL -2
#define NOT_SQUARE -3

void print_matrix(int n, int m, float *a[m]) // функция печати массива
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (fabs(a[i][j] - (int)a[i][j]) > 0)
                printf("%.3f ", a[i][j]);
            else if ((a[i][j] - (int)a[i][j]) == 0)
                printf("%d ", (int)a[i][j]);
            //printf("\n");
        }
        printf("\n");
    }
    printf("\n");
		}


void free_matrix_rows(float **data, int n)
{
    for (int i = 0; i < n; i++)
       // free можно передать NULL
       free(data[i]);

    free(data);
}


float** allocate_matrix_rows(int n, int m, FILE *f)
{
    float num;
    float **data = calloc(n, sizeof(float*));
    if (!data)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        data[i] = malloc(m * sizeof(float));
        if (!data[i])
        {
            free_matrix_rows(data, n);
            return NULL;
        }
        for(int j = 0; j < m; j++)
        {
            fscanf(f, "%f", &num);
            data[i][j] = num;
            //printf("%f\n",data[i][j] );
        }
        
    }

    return data;
}

float** alloc(int n, int m)
{
    float **data = calloc(n, sizeof(float*));
    if (!data)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        data[i] = malloc(m * sizeof(float));
        if (!data[i])
        {
            free_matrix_rows(data, n);
            return NULL;
        }
    }

    return data;
}



int filtr(FILE *f)
{
    float n, m;
    float dec;
    int i = 0;
    if (fscanf(f,"%f", &n) != 1 || fscanf(f,"%f", &m) != 1) // проверка на букву в размерности
        return INCORRECT;
    if (n == 0 || m == 0) // проверка на размерность 0 0 и отсутствие элементов
        return INCORRECT;
    if (fabs(n - (int)n) > 0 || fabs(m - (int)m) > 0 ) // вещественная размерность
        return INCORRECT;
    if (n < 0 || m < 0) // отрицательная размерность
        return INCORRECT;
    while (fscanf(f,"%f",&dec) == 1) // несоответствие размерноти и кол-ва эл-тов
    {
        i++;
        //printf("%f\n", dec);
    }

    if (i != (int)n * (int)m)
        return INCORRECT;

    return OK;
}


float determ(float** Arr, int size, int m)
{
         if (size != m)
            return INCORRECT;
        int i,j;
        float det=0;
        float** matr;
        if(size==1)
        {
                det=Arr[0][0];
        }
        else if(size==2)
        {
                det=Arr[0][0]*Arr[1][1]-Arr[0][1]*Arr[1][0];
        }
        else
        {
                matr = calloc((size-1),sizeof(float*));
                for(i=0;i<size;++i)
                {
                        for(j=0;j<size-1;++j)
                        {
                                if(j<i) 
                                        matr[j]=Arr[j];
                                else
                                        matr[j]=Arr[j+1];
                        }
                        det+=pow((float)-1, (i+j))*determ(matr, size-1,m-1)*Arr[i][size-1];
                }
                free(matr);
                
        }
        return det;
}

int sum(int n, int m, float a[], float b[], float **result)
{
    //printf("%d\n",n);
    if (n < 0 || m < 0) // проверка некоректного ввода размерности
        return INCORRECT;

    *result = malloc(n * m * sizeof(int));
    float* array = *result;
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            *array = a[i*m + j] + b[i*m + j];
            //printf("%f\n", *array);
            array++;
        }
    }
    return OK;
}

void create_matrix(float* data, FILE *f)
{
    float num;
    float* array = data;
    while (fscanf(f, "%f", &num) == 1)
    {

        *array = num;
        array++;
    }
}

int multiply(int n1, int m1, float *a[m1], int n2, int m2, float *b[m2], float *result[m2])
{
   // printf("%d %dn", n1,m2);
    if (n1 != m2)
        return INCORRECT;

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            for (int k = 0; k < m1; k++)
            {
                //printf("%f %f", a[i][k], b[k][j]);
                //printf("i: %d, j: %d k: %d\n", i,j,k);
                result[i][j] += (a[i][k]) * (b[k][j]);
                //printf("%f\n", result[i][j]);
            }
        }
    }
    return OK;
}


void print_mass(float a[], int n,int m) // функция печати массива
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (fabs(a[i*m+j] - (int)a[i*m+j]) > 0)
                printf("%.3f ", a[i*m+j]);
            else if ((a[i*m+j] - (int)a[i*m+j]) == 0)
                printf("%d ", (int)a[i*m+j]);
        }
        printf("\n");
    }
    printf("\n");
}

