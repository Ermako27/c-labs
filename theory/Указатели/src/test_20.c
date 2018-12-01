/*
ƒемонстраци€ "св€зи" массива и указател€ (слайд 21)

    int a[...]
    int *pa = a

    a[i] <=> *(pa + i)
    &a[i] <=> pa + i
*/

#include <stdio.h>

int main(void)
{
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int *pa = a;

    printf("Array a - %p\n", a);
    printf("Pointer to array pa - %p\n", pa);

    printf("\n\n");

    for (int i = 0; i < n; i++)
        printf("pa + %d = %p\n", i, pa + i);

    printf("\n\n");

    for (int i = 0; i < n; i++)
        printf("pa + %d = %p, &a[%d] = %p\n", i, pa + i, i, &a[i]);

    printf("\n\n");

    for (int i = 0; i < n; i++)
        printf("*(pa + %d) = %d, a[%d] = %d\n", i, *(pa + i), i, a[i]);

    printf("\n\n");

    return 0;
}