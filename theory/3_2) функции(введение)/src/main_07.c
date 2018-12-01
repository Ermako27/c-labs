//
// Слайд 14 (решение без ошибки в main_08.c)
//


#include <stdio.h>

int main(void)
{
    // error: implicit declaration of function 'avg'
    float a = avg(2.0, 3.0);

    printf("%f\n", a);

    return 0;
}

float avg(float a, float b)
{
    return (a + b) / 2.0;
}