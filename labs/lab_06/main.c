#include <stdio.h>
#include "printmass.h"
#include "readfile.h"
#include "sort.h"
#include "diffitems.h"
#define N 100
#define OK 1
#define OVERFLOW -1




int main(int argc, char **argv)
{
    FILE *f;
    int a[N];
    int read_error; // код ошибки
    int size; // размер массива
    int count; // количество различных элементов
    int num; // для проверки на пустоту

    if (argc != 2) // проверка на наличие аргумента
    {
        fprintf(stderr, "Not enough arguments\n");
    }
    else
    {
        f = fopen(argv[1], "r"); // успешное открытие файла
        if (f == NULL)
        {
            fprintf(stderr, "Could not open file\n");
        }
        else
        {
            if (fscanf(f, "%d", &num) == 1) // проверка на пустой файл
            {
                rewind(f);
                read_error = read_file(f,a,&size);
                if (read_error == OK)
                {
                    printf("array: ");
                    print_mass(a, size);
                    sort(a, a, a + size);
                    printf("sorted array: ");
                    print_mass(a, size);
                    count = diff_items(a, a + size);
                    printf("Count of different elements: %d", count);
                }
                else if (read_error == OVERFLOW)
                {
                    printf("There are more than 100 elements in file.\n");
                    printf("Work was done only with first 100 elements\n");
                    printf("array: ");
                    print_mass(a, size);
                    sort(a, a, a + size);
                    printf("sorted array: ");
                    print_mass(a, size);
                    count = diff_items(a, a + size);
                    printf("Count of different elements: %d", count);
                }
            }
            else
            {
                printf("File is empty!!!");
            }
        }
    }
    return 0;
}
