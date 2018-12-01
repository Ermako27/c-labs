#include <stdio.h>
#define N 100
#define OK 1
#define OVERFLOW -1

void print_mass(int a[], int size) // функция печати массива
{
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int read_file(FILE *f, int* pb) // запись чисел из файла в массив
{
    int* pcur = pb;
    int num;
    while (fscanf(f, "%d", &num) == 1)
    {
        *pcur = num;
        pcur++;


    }
    return OK;
}

void sort(int *array,int *s_array, int *end) // сортировка для последующего подсчета различных элементов
{
   // printf("array: %d, end: %d ", *array, *end);
    //while (array < end && (*array) > 0)
    while (array < end)
    {
        int *j = s_array; // указатель для второго цикла т.к. первый меняется
        //printf("iteration\n");
        //while (j < end -1 && (*j > 0))
        while (j < end -1)
        {
            //printf("J: %d J+1: %d\n", *j, *(j+1));
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
}



int main(int argc, char **argv)
{
    FILE *f;
    int a[N];
    int read_error; // код ошибки
    int size; // размер массива
    //int count; // количество различных элементов
    //int num; // для проверки на пустоту
    int b;
    printf("input: ");
    scanf("%d",&b);





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


            if (fscanf(f, "%d", &size) == 1) // проверка на пустой файл
            {
                rewind(f);
                read_error = read_file(f,a);
                if (read_error == OK)
                {
                    a[0] = b;
                    sort(a, a, a + size +1);
                    printf("sorted array: ");
                    print_mass(a, size+1);
                }

            }
            else
            {
                printf("File is empty!!!");
            }
        }
        fclose(f);
    }
    return 0;
}
