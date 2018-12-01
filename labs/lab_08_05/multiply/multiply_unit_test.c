#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 0
#define INCORRECT 1
#define UNEQUAL 2

// n - кол-во строк
// м - кол-во столбцов


void free_matrix_rows(float **data, int n)
{
    for (int i = 0; i < n; i++)
       // free можно передать NULL
       free(data[i]);

    free(data);
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
        }
    }

    return data;
}

// сравнение получившейся матрицы и ожидаемого результата
int compare(int n, int m, float *a[m], float *b[m])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (fabs(a[i][j] - b[i][j]) > 0.01)
				return UNEQUAL;
		}
	}
	return OK;
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

void test_multiply(void)
{
	int err_count = 0;
	float **first_matrix;
	float **second_matrix;
    float **target1;
    float **res;
	FILE *f1;
    FILE *f2;
    FILE *f3;
    int n1, m1, n2, m2;


// тепличный тест умножение квадратных матриц

    f1 = fopen("test1.txt", "r");
    f2 = fopen("test2.txt", "r");
    f3 = fopen("target1.txt", "r");
    fscanf(f1,"%d", &n1);
    fscanf(f1,"%d", &m1);
    fscanf(f2,"%d", &n2);
    fscanf(f2,"%d", &m2);
    first_matrix = allocate_matrix_rows(n1,m1,f1);
    second_matrix = allocate_matrix_rows(n2,m2,f2);
    target1 = allocate_matrix_rows(n1,m2,f3);
    res = alloc(n1,m2);
    multiply(n1,m1,first_matrix,n2, m2,second_matrix, res);
    
    if (compare(n1,m2,target1,res) != OK)
    {
      printf("1\n");
      err_count++;
    }

// тепличный тест умножение матриц разных размерностей (3,2)(2,3)

    f1 = fopen("test3.txt", "r");
    f2 = fopen("test4.txt", "r");
    f3 = fopen("target2.txt", "r");
    fscanf(f1,"%d", &n1);
    fscanf(f1,"%d", &m1);
    fscanf(f2,"%d", &n2);
    fscanf(f2,"%d", &m2);
    first_matrix = allocate_matrix_rows(n1,m1,f1);
    second_matrix = allocate_matrix_rows(n2,m2,f2);
    target1 = allocate_matrix_rows(n1,m2,f3);
    res = alloc(n1,m2);
    multiply(n1,m1,first_matrix,n2, m2,second_matrix, res);
    
    if (compare(n1,m2,target1,res) != OK)
    {
      printf("2\n");
      err_count++;
    }


// проверка условия умножения матриц: колчичество строк 1 матрицы
                        // должно быть равно количеству столбцов второй

    if (multiply(2,2,first_matrix,5,5,second_matrix, res) != INCORRECT)
    {
      printf("3\n");
      err_count++;
    }

// тест с разными типами и знаками
    f1 = fopen("test5.txt", "r");
    f2 = fopen("test6.txt", "r");
    f3 = fopen("target3.txt", "r");
    fscanf(f1,"%d", &n1);
    fscanf(f1,"%d", &m1);
    fscanf(f2,"%d", &n2);
    fscanf(f2,"%d", &m2);
    first_matrix = allocate_matrix_rows(n1,m1,f1);
    second_matrix = allocate_matrix_rows(n2,m2,f2);
    target1 = allocate_matrix_rows(n1,m2,f3);
    res = alloc(n1,m2);
    multiply(n1,m1,first_matrix,n2, m2,second_matrix, res);
    
    if (compare(n1,m2,target1,res) != OK)
    {
      printf("4\n");
      err_count++;
    }


	printf("%s: %s\n", __func__, err_count ? "FAILED" : "OK");

}

int main(void)
{
	test_multiply();
	return 0;
}
