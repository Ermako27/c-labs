//
// ����� 16
//


#include <stdio.h>

float avg(float a, float b);

/*
// ����� � ���
float avg(float, float);
*/

int main(void)
{
    float a = avg(2.0, 3.0);

    printf("%f\n", a);

    return 0;
}

float avg(float a, float b)
{
    return (a + b) / 2.0;
}