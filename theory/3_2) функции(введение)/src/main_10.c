//
// Слайд 20
//


#include <stdio.h>

int power(int base, int n)
{
    int res = 1;

    while (n > 0)
    {
        res = res * base;
        n = n - 1;
    }

    printf("[DBG] power n = %d\n", n);

    return res;
}

int main(void)
{
    int a, n = 5;

    printf("[DBG] main n = %d\n", n);

    a = power(2, n);

    printf("%d^%d = %d\n", 2, n, a);

    return 0;
}
