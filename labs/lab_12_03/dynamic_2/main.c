// динамическая загрузка(не компоновка) библиотеки

/*

для будущего меня: огромный ворох переменных для храниения
адресов функций в библиотеке - единственное что я успел нагуглить 
в 1:49, 100% есть иной способ, но пока пуст хоть так

(где нашел: http://www.firststeps.ru/linux/r.php?8)
(вот тут тоже норм: https://www.ibm.com/developerworks/ru/library/l-dynamic-libraries/index.html)


*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include "functions.h"

#define OK 0
#define ALLOCERR 1
#define SORTERR 2
#define N 5


int main(int argc, char **argv)
{
    void *handler;  // хэндлер внешней библиотеки
    void *ext_library; // 



    // тот самый ворох

    void (*dyn_print_mass)(float*, int);

    int (*dyn_array_count)(FILE*, int*);

    void (*dyn_array_create)(float*, FILE*);

    int (*dyn_filtr_count)(FILE*, int*, float*);

    void (*dyn_array_create_f)(float*, FILE*, float);

    void (*dyn_sort)(void*, size_t, size_t, int (*compare)(const void*, const void*));

    int (*dyn_compare)(const void*, const void*);

    unsigned long long (*dyn_tick)(void);





    ///////////////
    unsigned long long tb, te;
    unsigned long long tbq, teq;
    float sum;
    float num;
    int filter_error;
    int array_error;
    float *array;
    int n;
    FILE *f;

    // загрузка библиотеки
    ext_library = dlopen("./libdynfunc.so",RTLD_LAZY);

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

                        // в данном случае переменная содержащая адресс функции из либы 
                        // по названию совпадает с именем в функции в самой либе (хз заработает или нет)
                        dyn_filtr_count = dlsym(ext_library, "filtr_count");
                        // printf("1\n");
                        filter_error = (*dyn_filtr_count)(f,&n, &sum);
                        // printf("2\n");
                        array = malloc(n*sizeof(float));  // выделение памяти с вызывающей стороны
                        // printf("3\n");
                        fclose(f);
                        // printf("4\n");
                        if (filter_error == OK)
                        {
                            // printf("5\n");
                            f = fopen(argv[2], "r");
                            // printf("6\n");
                            dyn_array_create_f = dlsym(ext_library, "array_create_f");
                            // printf("7\n");
                            (*dyn_array_create_f)(array, f, sum);
                            // printf("8\n");
                            fclose(f);
                            // printf("9\n");
                            dyn_sort = dlsym(ext_library, "sort");
                            // printf("10\n");
                            dyn_compare = dlsym(ext_library, "compare");
                            // printf("11\n");
                            dyn_tick = dlsym(ext_library, "tick");
                            // printf("12\n");
                            tb= (*dyn_tick)();
                            // printf("13\n");
                            (*dyn_sort)(array, sizeof(array) / sizeof(array[0]),sizeof(array[0]),dyn_compare);
                            // printf("14\n");
                            dyn_tick = dlsym(ext_library, "tick");
                            // printf("15\n");
                            te= (*dyn_tick)();

                            // printf("16\n");
                            dyn_tick = dlsym(ext_library, "tick");
                            // printf("17\n");
                            tbq= (*dyn_tick)();
                            // printf("18\n");
                            qsort(array,sizeof(array) / sizeof(array[0]),sizeof(array[0]),dyn_compare);
                            // printf("19\n");
                            dyn_tick = dlsym(ext_library, "tick");
                            // printf("20\n");
                            teq= (*dyn_tick)();
                            // printf("21\n");
                            dyn_print_mass = dlsym(ext_library, "print_mass");
                            // printf("22\n");
                            (*dyn_print_mass)(array,n);
                            // printf("23\n");
                            printf("my sort time: %llu\n", (te - tb) / N);
                            printf("qsort time: %llu\n", (teq - tbq) / N);
                            // printf("24\n");

                        }
                        else if (filter_error == ALLOCERR)
                        {
                            printf("Memmory allocation error");
                        }
                    }
                    else if (strcmp(argv[1], "-") == 0)
                    {

                        dyn_array_count = dlsym(ext_library, "array_count");
                        array_error = (*dyn_array_count)(f,&n);
                        //printf("%d\n", n);
                        if (array_error == OK)
                        {
                            array = malloc(n*sizeof(float)); // выделение памяти с вызывающей стороны
                            f = fopen(argv[2], "r");

                            dyn_array_create = dlsym(ext_library, "array_create");
                            (*dyn_array_create)(array, f);
                            fclose(f);

                            dyn_sort = dlsym(ext_library, "sort");
                            dyn_compare = dlsym(ext_library, "compare");
                            dyn_tick = dlsym(ext_library, "tick");
                            tb= (*dyn_tick)();
                            (*dyn_sort)(array, sizeof(array) / sizeof(array[0]),sizeof(array[0]),dyn_compare);
                            dyn_tick = dlsym(ext_library, "tick");
                            te= (*dyn_tick)();

                            dyn_tick = dlsym(ext_library, "tick");
                            tbq= (*dyn_tick)();
                            qsort(array,sizeof(array) / sizeof(array[0]),sizeof(array[0]),dyn_compare);
                            dyn_tick = dlsym(ext_library, "tick");
                            teq= (*dyn_tick)();

                            dyn_print_mass = dlsym(ext_library, "print_mass");
                            (*dyn_print_mass)(array,n);
                            printf("my sort time: %llu\n", (te - tb) / N);
                            printf("qsort time: %llu\n", (teq - tbq) / N);


                        }
                        else if (array_error == ALLOCERR)
                        {
                            printf("Memmory allocation error");
                        }
                    }


                }
                else
                {
                    printf("File is empty!!!\n");
                }
            }
        }
        return 0;
}
