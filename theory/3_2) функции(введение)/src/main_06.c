//
// ����� 12
//


#include <stdio.h>

int main(void)
{
    int n_chars;

    n_chars = printf("Hello, world!\n");
    // ����� ������ printf n_chars ����� 14
    printf("n_chars = %d\n", n_chars);

    (void) printf("Hello, world!\n");
    // ���� �������, ��� ������������ �������� �� ������������

    return 0;
}