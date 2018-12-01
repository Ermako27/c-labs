//
// Слайды 5, 9
//


#include <stdio.h>

void print_pos_num(int a)
{
    if (a < 0)
        return;

    printf("%d\n", a);
}

int main(void)
{
    int a;

    printf("Enter a: ");
    scanf("%d", &a);

    print_pos_num(a);

    return 0;
}
