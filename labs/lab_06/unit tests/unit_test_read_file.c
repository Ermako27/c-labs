#include <stdio.h>

#define OK 0
#define ERR_INVALID_PARAM   -1
#define EMPTY_FILE -2
#define OVERFLOW -3

int read_file(FILE *f, int* pb, int *size) // запись чисел из файла в массив
{
    int* pcur = pb;
    if (size != NULL)
        *size = 0;
    int num;
    if (pb == NULL || size == NULL || f == NULL)
        return ERR_INVALID_PARAM;
    if (fscanf(f, "%d", &num) != 1) //проверка на пустой файл, нужно ли ее писать в тесте?
        return EMPTY_FILE;

    while (fscanf(f, "%d", &num) == 1)
    {
        if (*size < 100)
        {
            *pcur = num;
            pcur++;
            *size += 1; // размер массива
        }
        else
            return OVERFLOW;
    }
    return OK;
}

void test_read(void)
{
    FILE *f;
    FILE *t4;
    FILE *t3;
    FILE *t2;
    FILE *t5;
    FILE *e;
    int err_count = 0;
    f = fopen("test.1.txt", "r");
    e = fopen("test.5.txt", "r");
    int a[100];
    int size;

    // Неверные параметры

    if (read_file(NULL, a, &size) != ERR_INVALID_PARAM)
    {
        err_count++;
    }

    if (read_file(f, NULL, &size) != ERR_INVALID_PARAM)
    {
        err_count++;
        fclose(f);
    }
    f = fopen("test.1.txt", "r");
    if (read_file(f, a, NULL) != ERR_INVALID_PARAM)
    {
        err_count++;
        fclose(f);
    }

    // Пустой файл

    if (read_file(e, a, &size) != EMPTY_FILE)
    {
        err_count++;
    }

    // Разные корректные данные

    t2 = fopen("test.2.txt", "r");
    t3 = fopen("test.3.txt", "r");
    t4 = fopen("test.4.txt", "r");
    t5 = fopen("test.8.txt", "r");

    if (read_file(t2, a, &size) != OK)
    {
        err_count++;
    }
    if (read_file(t3, a, &size) != OK)
    {
        err_count++;
    }
    if (read_file(t4, a, &size) != OK)
    {
        err_count++;
    }
    if (read_file(t5, a, &size) != OVERFLOW)
    {
        err_count++;
    }

    fclose(t2);
    fclose(t3);
    fclose(t4);
    fclose(t5);
    fclose(e);

    printf("%s: %s\n", __func__, err_count ? "FAILED" : "OK");
}

int main(void)
{
    test_read();

    return 0;
}
