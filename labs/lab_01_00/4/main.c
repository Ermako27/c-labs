#include <stdio.h>

int main(void)
{
    int price = 45;
    int s, bottles;

    printf("input amount of money: ");
    scanf("%d", &s);
    bottles = s/price; // количество бутылок
    printf("Amount of bottles: %d\n", bottles);

    return 0;
}
