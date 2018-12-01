//
// Слайд 17
//


#include <stdio.h>

void f()
{
    printf("f\n");
}

void g(void)
{
    printf("g\n");
}

int main(void)
{
    f();

    g();

    f(1, 2, 3);

    /*
    // error: too many arguments to function 'g'
    g(1, 2, 3);
    */

    return 0;
}
