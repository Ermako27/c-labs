//
// Слайд 22: попытки продемонстрировать к чему может привести наличие символов в строке форматирования функции scanf
//


#include <stdio.h>

int main(void)
{
    int i, j;

/*
    scanf("%d %d", &i, &j);
*/
/*
    scanf("%d,%d", &i, &j);
*/
    scanf("%d%d", i, j);
    printf("%d %d\n", i, j);

    return 0;
}