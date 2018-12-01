//
// Слайды 1, 10
//


#include <stdio.h>

float avg(float a, float b)
{
    float c;

    c = a + b;

    return c / 2.0;
}

int main(void)
{
    float a, b, c;

    a = 5.0;
    b = 3.0;
    c = avg(a, b);

    printf("Average of %f and %f is %f\n", a, b, c);

    printf("Enter a and b: ");
    scanf("%f%f", &a, &b);

    if (avg(a, b) < 0.0)
        printf("Average of %f and %f is negative\n", a, b);

    return 0;
}