#include <stdio.h>

#define OK 0
#define ERR_INVALID_PARAM   -1
#define ERR_NO_DATA         -2



int sort(int *array,int *s_array, int *end) // сортировка для последующего подсчета различных элементов
{
	//printf("end:", *end);
	
	if (array == NULL || s_array == NULL || end == NULL)
		return ERR_INVALID_PARAM;
	
	if (end == array)
		return ERR_NO_DATA;
	
    while (array < end)
    {
        int *j = s_array; // указатель для второго цикла т.к. первый меняется
        while (j < end -1)
        {
            if (*j > *(j+1))
            {
                //printf("swap\n");
                int t = *j;
                *j = *(j+1);
                *(j+1) = t;

            }
            j++;
        }
        array++;
    }
	
	return OK;
}

void test_sort(void)
{
	int err_count = 0;
	int a1[] = {5,4,3,2,1};
	int a2[] = {5,3,9,1,4};
	int a3[] = {-1,-2,-3,-4,-5};
	
	// Неверные данные
	
	if (sort(NULL, a1, a1 + 5) != ERR_INVALID_PARAM)
	{
		err_count++;
		printf("1");
	}
	if (sort(a1, NULL, a1 + 5) != ERR_INVALID_PARAM)
	{
		err_count++;
		printf("2");
	}
	if (sort(a1, a1, NULL) != ERR_INVALID_PARAM)
	{
		err_count++;
		printf("3");
	}
	
// Пустой массив
	if (sort(a1, a1, a1) != ERR_NO_DATA)
	{
		err_count++;
		printf("4");
	}
	
	
	// Корректные данные
	if (sort(a1, a1, a1+5) != OK)
	{
		err_count++;
		printf("5");
	}
	if (sort(a2, a2, a2+5) != OK)
	{
		err_count++;
		printf("6");
	}
	if (sort(a3, a3, a3+5) != OK)
	{
		err_count++;
		printf("7");
	}
	
	//printf("err: %d", err_count);
	
	printf("%s: %s\n", __func__, err_count ? "FAILED" : "OK");
}

int main(void)
{
    test_sort();
    return 0;
}