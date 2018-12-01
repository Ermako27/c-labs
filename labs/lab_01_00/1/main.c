#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define s 2
int abs(int a);
int main(void)
{
    int osn_1, osn_2, height;
    float side, c, perimetr;

    printf("input grounds: "); // основания
    scanf("%d%d", &osn_1, &osn_2);
    printf("input height: "); // высота
    scanf("%d", &height);
    c = abs(osn_1 - osn_2)/s; // полуразность оснований для нахождения боковой стороны
    side = sqrt(c*c + height*height); // боковая сторона
    perimetr = s*side + osn_1 + osn_2; // периметр
    printf("Perimetr equals: %f\n", perimetr);


    return 0;
}
