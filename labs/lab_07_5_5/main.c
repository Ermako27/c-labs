#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

#define OK 0
#define ALLOCERR 1
#define SORTERR 2




int main(int argc, char **argv)
{
    printf("!!!!!!!!!!!1");
    float num;
    int filter_error;
    int array_error;
    int sort_error;
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
                    if (strcmp(argv[1], "+") == 0)
                    {
                        filter_error = filtr_count(f, &array,&n);
                        fclose(f);
                        if (filter_error == OK)
                        {
                            f = fopen(argv[2], "r");
                            array_create_f(array, f);
                            fclose(f);
                            sort_error = sort(array, n);
                            print_mass(array,n);
                            printf("%d", sort_error);

                        }
                        else if (filter_error == ALLOCERR)
                        {
                            printf("Memmory allocation error");
                        }
                    }
                    else if (strcmp(argv[1], "-") == 0)
                    {
                        array_error = array_count(f, &array,&n);
                        fclose(f);
                        if (array_error == OK)
                        {
                            f = fopen(argv[2], "r");
                            array_create(array, f);
                            fclose(f);
                            sort_error = sort(array, n);
                            print_mass(array,n);
                            printf("%d", sort_error);

                        }
                        else if (array_error == ALLOCERR)
                        {
                            printf("Memmory allocation error");
                        }
                    }


                }
                else
                {
                    printf("File is empty!!!");
                }
            }
            fclose(f);
            free(array);
        }
        return 0;
}
