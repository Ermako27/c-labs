#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

#define OK 0
#define ALLOCERR 1
#define SORTERR 2
#define N 5


int main(int argc, char **argv)
{
    unsigned long long tb, te;
    unsigned long long tbq, teq;
    float sum;
    float num;
    int filter_error;
    int array_error;
    float *array;
    int n;
    FILE *f;
    if (argc != 3) // проверка на наличие аргумента
        {
            fprintf(stderr, "Not enough arguments\n");
        }
        else
        {
            f = fopen(argv[2], "r"); // успешное открытие файла
            if (f == NULL)
            {
                fprintf(stderr, "Could not open file\n");
            }
            else
            {
                if (fscanf(f, "%f", &num) == 1) // проверка на пустой файл
                {
                    rewind(f);
                    if ((strcmp(argv[1], "+") != 0) && ((strcmp(argv[1], "-") != 0)))
                    {
                        printf("Second argument should be + or -.\n");
                        return 0;
                    }
                    if (strcmp(argv[1], "+") == 0)
                    {
                        filter_error = filtr_count(f, &array,&n, &sum);
                        printf("%d\n", n);
                        fclose(f);
                        if (filter_error == OK)
                        {
                            f = fopen(argv[2], "r");
                            array_create_f(array, f, sum);
                            fclose(f);

                            tb= tick();
                            sort(array, sizeof(array) / sizeof(array[0]),sizeof(array[0]),compare);
                            te = tick();

                            tbq = tick();
                            qsort(array,sizeof(array) / sizeof(array[0]),sizeof(array[0]),compare);
                            teq = tick();

                            print_mass(array,n);
                            printf("my sort time: %llu\n", (te - tb) / N);
                            printf("qsort time: %llu\n", (teq - tbq) / N);

                        }
                        else if (filter_error == ALLOCERR)
                        {
                            printf("Memmory allocation error");
                        }
                    }
                    else if (strcmp(argv[1], "-") == 0)
                    {
                        array_error = array_count(f, &array,&n);
                        printf("%d\n", n);
                        if (array_error == OK)
                        {
                            f = fopen(argv[2], "r");
                            array_create(array, f);
                            fclose(f);
                            tb= tick();
                            sort(array, sizeof(array) / sizeof(array[0]),sizeof(array[0]),compare);
                            te = tick();
                            tbq = tick();
                            qsort(array,sizeof(array) / sizeof(array[0]),sizeof(array[0]),compare);
                            teq = tick();
                            print_mass(array,n);
                            printf("my sort time: %llu\n", (te - tb) / N);
                            printf("qsort time: %llu\n", (teq - tbq) / N);


                        }
                        else if (array_error == ALLOCERR)
                        {
                            printf("Memmory allocation error");
                        }
                    }
                    free(array);


                }
                else
                {
                    printf("File is empty!!!\n");
                }
            }
        }
        return 0;
}
