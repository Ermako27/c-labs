//
// Слайд 12
//


#include <stdio.h>

int main(void)
{
    int n_chars;

    n_chars = printf("Hello, world!\n");
    // после вызова printf n_chars равно 14
    printf("n_chars = %d\n", n_chars);

    (void) printf("Hello, world!\n");
    // явно указано, что возвращаемое значение не используется

    return 0;
}