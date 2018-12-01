//
// Слайды 5, 9, 11
//


#include <stdio.h>

void beep(void)
{
    printf("\a");
}

int main(void)
{
    beep();

    /*
    // error: statement with no effect
    beep;
    */

    return 0;
}
