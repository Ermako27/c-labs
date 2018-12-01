#include <stdio.h>
#include <math.h>
int len(int num)
{
    int n = 0;
    while (num)
    {
        num = num/10;
        n++;
    }
    //printf("%d", n);
    return n;
}


int main(void)
{
    int i; // счетчик
    int num; // вводимое число
    int n; // изменяемое количество цифр в числе
    int c; // отдельная цифра числа
    int k; // неизменяемое количество цифр в числе для цикла
    printf("Input number: ");
    if (scanf("%d", &num) == 1)
    {
        k = len(num);
        n = len(num) - 1;
        //printf("%d", n);
        for(i = 0; i < k; i++)
        {
            //printf("%d%d", i,n);
            c = num / pow(10, n);
            printf("%d", c);
            num = num - c*pow(10,n);
            n--;
        }
    }
    else
    {
        printf("Inputed wrong type!!!");
    }
    return 0;
}
