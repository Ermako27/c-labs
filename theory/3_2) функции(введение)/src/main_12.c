#include <stdio.h>
#include <math.h>

float length(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1, dy = y2 - y1;

    return sqrt(dx * dx + dy * dy);
}

float square(float a, float b, float c)
{
    float p = (a + b + c) / 2.0;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main(void)
{
    float x1, y1, x2, y2, x3, y3, x4, y4;
    float a, b, c, d, e;
    float s1, s2;

    printf("Coordinates of point 1: ");
    scanf("%f%f", &x1, &y1);

    printf("Coordinates of point 2: ");
    scanf("%f%f", &x2, &y2);
	
    printf("Coordinates of point 3: ");
    scanf("%f%f", &x3, &y3);

    printf("Coordinates of point 4: ");
    scanf("%f%f", &x4, &y4);

    a = length(x1, y1, x2, y2);
    b = length(x2, y2, x3, y3);
    c = length(x3, y3, x4, y4);
    d = length(x4, y4, x1, y1);
    e = length(x1, y1, x3, y3);

    s1 = square(a, b, e);
    s2 = square(d, e, c);

    printf("s is = %f\n", s1 + s2);

    return 0;
}
