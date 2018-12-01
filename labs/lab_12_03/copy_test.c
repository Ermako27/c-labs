#include <stdio.h>
#include <stdlib.h>


#define INCORRECT -1
#define OK 1

void data_copy(int *a, int *b, int n, int key)
{
	int k = 0;
	// if(n <= 0)
 //        return INCORRECT;

    b = malloc(n * 2 * sizeof(int));
    // for (int i = 0; i < n; i++)
    // {
    // 	//printf("i: %d\n", i);
    // 	if ((i + 1) % 2 == 0)
    // 	{
    // 		//printf("if: %d\n", (i + 1) % 2 );
    // 		b[i+1] = key;
    // 		k++;
    // 	}
    // 	b[i+k] = a[i];
    // }

    for (int i = 1; i < n; i++)
    {
    	
    }

    // return OK;
}


int main(void)
{
	int a[] = {1,2,3,4,5};
	int *ptra = a;

	int *ptrb = NULL;
	int key = 0;

	for (int i = 0; i < 5; i++)
	{
		printf("%d | ", ptra[i]);
	}
	printf("\n");


	data_copy(ptra,ptrb, 5, key);
	printf("1\n");

	for (int i = 0; i < 10; i++)
	{
		printf("%d | ", ptrb[i]);
	}

	return 0;

}
