//
// Слайды 5, 9
//


#include <stdio.h>

int max(int a, int b)
{
    if (a < b)
        return b;

    return a;
}

int main(void)
{
    int a, b;

    printf("Enter a and b: ");
    scanf("%d%d", &a, &b);

    printf("Max(%d, %d) is %d\n", a, b, max(a, b));

    return 0;
}