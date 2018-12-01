#include <stdio.h>


int main(void)
{
    int chest, mass;
    float n_weight, index, height;
    printf("input height: "); // рост
    scanf("%f", &height);
    printf("input chest: "); // обхват груди
    scanf("%d", &chest);
    printf("input mass: "); // вес
    scanf("%d", &mass);

    n_weight = height*chest/240; // нормальный вес
    height /= 100; // перевод сантиметры в метры
    index = mass/(height*height);
    printf("Normal weight: %f\n", n_weight);
    printf("Index of weight: %f\n", index);

    return 0;
}
