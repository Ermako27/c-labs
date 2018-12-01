#include<stdio.h>
#include<math.h>

float F(float x) // функция f(x)
{
    float f;
    f = 1/sqrt(1 - x*x);
    return f;
}


float S(float x, float eps) // ряд s(x)
{
    int n_ch = -1; //  коэф в числителе
    int n_zn = 0; // коэф в знаменателе
    float s = 1;
    float elem = 1;

    while(fabs(elem) > eps)
    {
        n_ch += 2;
        n_zn += 2;
        elem = elem*x*x*n_ch/n_zn;
        s += elem;
    }

    return s;

}


int main(void)
{
    float q1, q, x, eps;
    float absolute, relative, s, f;
    printf("Input the value of the argument |X| < 1: ");
    q1 = scanf("%f", &x);
    if (q1 != 1)
    {
        printf("Wrong value");
    }
    else
    {
        if (x <= -1 || x >= 1) // проверка на правильный ввод аргумента
        {
            printf("Wrong value");
        }
        else
        {
            printf("Input epsilon: ");
            q = scanf("%f", &eps);
            if (q != 1) // проверка на правильный ввод точности
            {
                printf("Wrong value");
            }
            else
            {
                s = S(x, eps);
                f = F(x);
                printf("\nApproximate value of the function s(x): %f", s);
                printf("\nThe exact value of the function f(x): %f", f);

                absolute = fabs(f - s);
                relative = fabs((f - s)/f);
                printf("\nAbsolute error: %f", absolute);
                printf("\nRelative error: %f", relative);
            }
        }
    }
}
