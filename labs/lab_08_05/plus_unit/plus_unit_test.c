#include <stdio.h>
#include <stdlib.h>


#define OK 0
#define UNEQUAL 1
#define INCORRECT 2

// сравнение получившейся матрицы и ожидаемого результата
int compare(int n, int m, float a[], float b[])
{
	int size = n*m;
	for (int i = 0; i < size; i++)
	{
		if (a[i] != b[i])
			return UNEQUAL; 
	}

	return OK;
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


void test_sum(void)
{
	int err_count = 0;

	float *res;


// тепличный тест на работоспособность

	int n1 = 2, m1 = 2;
	float a1[4] = {1,2,3,4};
	float b1[4] = {5,6,7,8};
	float target1[4] = {6,8,10,12};

	sum(n1,m1,a1,b1, &res);
	if (compare(n1,m1,target1,res) != OK)
	{
		printf("1\n");
		err_count++;
	}


// отрицательная размерность 

	int n2 = -2, m2 = 2;
    float a2[4] = {1,2,3,4};
	float b2[4] = {5,6,7,8};

	
	if (sum(n2,m2,a2,b2,&res) != INCORRECT)
	{
		printf("2\n");
		err_count++;
	}

// тепличный тест с разными типами и знаками

	int n3 = 2, m3 = 4;
	float a3[8] = {-1, 2.6, 3, 4.3, -9, 12, -5.2, 0};
	float b3[8] = {5, 6, 7, 8, -5, -1.3, 0, 7};
	float target3[8] = {4,8.6,10,12.3,-14,10.7,-5.2,7};

	sum(n3,m3,a3,b3, &res);
	if (compare(n3,m3,target3,res) != OK)
	{
		printf("3\n");
		err_count++;
	}

	printf("%s: %s\n", __func__, err_count ? "FAILED" : "OK");
	free(res);
}

int main(void)
{
	test_sum();
	return 0;
}