#include <stdio.h>
#include "printmass.h"

void print_mass(int a[], int size) // ������� ������ �������
{
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}