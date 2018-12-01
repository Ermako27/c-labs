#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 0
#define INCORRECT 1

int filtr(FILE *f)
{
	float n, m;
	float dec;
	int i = 0;
	if (fscanf(f,"%f", &n) != 1 || fscanf(f,"%f", &m) != 1) // проверка на букву в размерности
		return INCORRECT;


	if (fabs(n - (int)n) > 0 || fabs(m - (int)m) > 0 )
		return INCORRECT;
	if (n < 0 || m < 0)
		return INCORRECT;
	while (fscanf(f,"%f",&dec) == 1)
	{
		i++;
		//printf("%f\n", dec);
	}

	if (i != (int)n * (int)m)
		return INCORRECT;

	return OK;
}

void test_filt()
{
	int err_count = 0;
	FILE *f;

// вещественная размерность 

	f = fopen("test1.txt", "r");
	if (filtr(f) != INCORRECT)
	{
		printf("1\n");
		err_count++;
	}
	fclose(f);

// отрицательная размерность

	f = fopen("test2.txt", "r");
	if (filtr(f) != INCORRECT)
	{
		printf("2\n");
		err_count++;
	}
	fclose(f);

// размерность не соответствует размеру матрицы
	f = fopen("test3.txt","r");
	if (filtr(f) != INCORRECT)
	{
		printf("3\n");
		err_count++;
	}
	fclose(f);

// буква в матрице

	f = fopen("test4.txt","r");
	if (filtr(f) != INCORRECT)
	{
		printf("4\n");
		err_count++;
	}
	fclose(f);

// буква в размерности

	f = fopen("test5.txt","r");
	if (filtr(f) != INCORRECT)
	{
		printf("5\n");
		err_count++;
	}
	fclose(f);

// нулевая размерность 

	f = fopen("test6.txt","r");
	if (filtr(f) != INCORRECT)
	{
		printf("6\n");
		err_count++;
	}
	fclose(f);

	printf("%s: %s\n", __func__, err_count ? "FAILED" : "OK");
}

int main(void)
{
	test_filt();
	return 0;
}