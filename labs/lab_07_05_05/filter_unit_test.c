#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define OK 0
#define INVALID_PARAM -1
#define ALLOCERR -2



int array_create_f(float* data, FILE *f, float sum)
{
	if (data == NULL || f == NULL)
		return INVALID_PARAM;
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
    return OK;
}


int filtr_count(FILE *f, float **data, int *n, float *s)
{
	if (f == NULL || data == NULL || n == NULL || s == NULL)
		return INVALID_PARAM;

    int count = 0;
    float num;
    float sum = 0.0;
    *s = 0.0;
    while (fscanf(f, "%f", &num) == 1)
    {
        sum += num;
    }
    rewind(f);
    *s = sum;
    while (fscanf(f, "%f", &num) == 1)
    {
        sum -= num;
        if (num > sum)
        {
            count += 1;
           
        }
    }

    if (count)
    {
        *data = malloc(count * sizeof(float));
        *n = count;
        return OK;

    }
    else
    	return ALLOCERR;
}

void test_filt(void)
{
	int err_count = 0;
	float *a;
	FILE *f;
	FILE *e;
	int n = 0;
	float sum = 0;
	f = fopen("test5.txt", "r");
	e = fopen("test3.txt", "r");

	if (filtr_count(NULL, &a, &n, &sum) != INVALID_PARAM)
	{
		err_count++;
		printf("1");
	}

	if (filtr_count(f, NULL, &n, &sum) != INVALID_PARAM)
	{
		err_count++;
		printf("2");
	}

	if (filtr_count(f, &a, NULL, &sum) != INVALID_PARAM)
	{
		err_count++;
		printf("3");
	}

	if (filtr_count(f, &a, &n, NULL) != INVALID_PARAM)
	{
		err_count++;
		printf("4");
	}

	if (filtr_count(e, &a, &n, &sum) != ALLOCERR)
	{
		err_count++;
		printf("5\n");
	}

	if (filtr_count(f,&a,&n,&sum) != OK)
	{
		err_count++;
		printf("6");
	}

	if (array_create_f(NULL, f, sum) != INVALID_PARAM)
	{
		err_count++;
		printf("7\n");
	}
	if (array_create_f(a,NULL,sum) != INVALID_PARAM)
	{
		err_count++;
		printf("8\n");
	}
	if (filtr_count(f,&a,&n,&sum) != OK && array_create_f(a,f,sum) != OK)
	{
		err_count++;
		printf("9\n");
	}

	printf("%s: %s\n", __func__, err_count ? "FAILED" : "OK");

}

int main(void)
{
	test_filt();
	return 0;
}
