//
// Слайд 7
//

// Команда компиляции: gcc -std=c99 -pedantic -Wall -Werror -c main_05.c


#include <stdio.h>

// OK
void f1(void)
{
    int a = 5;
    printf("%d\n", a);
}

// ОК
void f2(void)
{
}	

// Вложенных функций в языке Си нет
void f3(void)
{
    // ошибка компиляции
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

// Попытка использовать переменную, которая определена в другой функции
void g4(void)
{
    // ошибка компиляции
    // error: 'a' undeclared (first use in this function)
    printf("%d\n", a);
}

