#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define INCORRECT -1



// !!!!!!!!!!! ИСПРАВИТЬ МОДУЛЬНЫЕ ТЕСТЫ!!!!!!!!!!!!!1
void simple_generate_test(void)
{
	int err_count = 0;
   
   // тепличный тест: 8 простых чисел
	int res1[] = {1,2,3,5,7,11,13,17};
	int *test1 = NULL;
	simple_numbers(&test1,8);
	for (int i = 0; i < 8; i++)
	{
		if (test1[i] != res1[i])
		{
			err_count += 1;
			break;
		}
	}


	// одно число 
	int res2[] = {1};
	int *test2 = NULL;
	simple_numbers(&test2,1);
	for (int i = 0; i < 1; i++)
	{
		if (test2[i] != res2[i])
		{
			err_count += 1;
			break;
		}
	}

	// 0 чисел
	int *test4 = NULL;
	if (simple_numbers(&test4, 0) != INCORRECT)
		err_count += 1;


	// отрицательное количетсво чисел
	int *test3 = NULL;
	if (simple_numbers(&test3, -1) != INCORRECT)
		err_count += 1;

	printf("%s: %s\n", __func__, err_count ? "FAILED" : "OK");
}

void copy_test(void)
{
	int err_count = 0;
	
	int key = 0;
	int test1[] = {1,2,3,4,5,6};
	int *copy1 = NULL;
	int res1[] = {1,2,0,3,4,0,5,6,0};
	data_copy(test1, &copy1,6,key);
	for (int i = 0; i < 9; i++)
	{
		if (copy1[i] != res1[i])
		{
			err_count += 1;
			break;
		}
	}
	
	int test2[] = {0,0,0,0,0};
	int *copy2 = NULL;
	int res2[] = {0,4,0,4,0,4,0,4,0,4};
	data_copy(test2, &copy2,5,4);
	for (int i = 0; i < 6; i++)
	{
		if (copy2[i] != res2[i])
		{
			err_count += 1;
			break;
		}
	}
	
	int test3[] = {-1,-3,-5};
	int *copy3 = NULL;
	int res3[] = {-1,-3,-5};
	data_copy(test3, &copy3,3,0);
	for (int i = 0; i < 3; i++)
	{
		if (copy3[i] != res3[i])
		{
			err_count += 1;
			break;
		}
	}
	
	int test4[] = {3,-4,6};
	int *copy4 = NULL;
	int res4[] = {3,-4,0,6,0};
	data_copy(test4, &copy4,3,0);
	for (int i = 0; i < 5; i++)
	{
		if (copy4[i] != res4[i])
		{
			err_count += 1;
			break;
		}
	}

	printf("%s: %s\n", __func__, err_count ? "FAILED" : "OK");
}

int main(void)
{
	simple_generate_test();
	copy_test();
}
