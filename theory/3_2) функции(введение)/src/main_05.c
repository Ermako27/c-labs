//
// ����� 7
//

// ������� ����������: gcc -std=c99 -pedantic -Wall -Werror -c main_05.c


#include <stdio.h>

// OK
void f1(void)
{
    int a = 5;
    printf("%d\n", a);
}

// ��
void f2(void)
{
}	

// ��������� ������� � ����� �� ���
void f3(void)
{
    // ������ ����������
    // error: ISO C forbids nested functions
    void g3(void)
    {
    }
}	

// OK
void f4(void)
{
    int a = 5;
    printf("%d\n", a);
}

// ������� ������������ ����������, ������� ���������� � ������ �������
void g4(void)
{
    // ������ ����������
    // error: 'a' undeclared (first use in this function)
    printf("%d\n", a);
}

