#include <stdio.h>
#define ERR_INVALID_PARAM   -1
#define ERR_NO_DATA         -2
#define OK 0
#define NOT_SORTED -3

int diff_items(int *array, int *end) // количетсво различных элементов
{
	if (array == NULL || end == NULL)
		return ERR_INVALID_PARAM;
	if (end == array)
		return ERR_NO_DATA;
	
    int *i = array;
    int item = *i;
    int count = 1;

    while (array < end)
    {
		if (*array > *(array + 1))
		{
			return NOT_SORTED;
		}
        if (item != *array)
        {
            //printf("item: %d array: %d\n", item, *array);
            item = *array;
            count += 1;
        }
        array++;
    }
    return OK;
}

void test_dif(void)
{
	int err_count = 0;
	int a1[] = {10,11,12,13,14,15};
	int a2[] = {5,3,9,1,4};
	int a3[] = {-5,-4,-3,-2,-1};
	// Неверные данные
	
	if (diff_items(NULL, a1 + 5) != ERR_INVALID_PARAM)
	{
		err_count++;
		printf("1");
	}
	if (diff_items(a1, NULL) != ERR_INVALID_PARAM)
	{
		err_count++;
		printf("3");
	}
	// Пустой массив
	if (diff_items(a1, a1) != ERR_NO_DATA)
	{
		err_count++;
		printf("4");
	}
	
	//Неотсортированный массив
	if (diff_items(a2, a2 + 5) != NOT_SORTED)
	{
		err_count++;
		printf("9");
	}
		
		
	// Корректные данные
	if (diff_items(a1, a1+5) != OK)
	{
		err_count++;
		printf("5");
	}
	if (diff_items(a3, a3+5) != OK)
	{
		err_count++;
		printf("7");
	}
	
	printf("%s: %s\n", __func__, err_count ? "FAILED" : "OK");
	
}

int main(void)
{
    test_dif();
    return 0;
}