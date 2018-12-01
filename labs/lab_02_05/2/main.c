#include <stdio.h>

float vec_multi(float ax, float ay, float bx, float by) // подсчет векторного произведения
{
    float vm;
    vm = ax*by - bx*ay; // векторное произведение

    return vm;


}

int linecross(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4) // определяет пересекаются ли два орезка
{
    float v1,v2,v3,v4;
    int result;
    v1 = vec_multi(x4-x3,y4-y3,x1-x3,y1-y3);
    v2 = vec_multi(x4-x3,y4-y3,x2-x3,y2-y3);
    v3 = vec_multi(x2-x1,y2-y1,x3-x1,y3-y1);
    v4 = vec_multi(x2-x1,y2-y1,x4-x1,y4-y1);
    if (v1*v2 < 0 && v3*v4 < 0)
    {
        result = 1;
        return result;
    }
    else
    {
        result = 0;
        return result;
    }
}

int main(void)
{
    float x1,y1,x2,y2,x3,y3,x4,y4;

    printf("input coordinates x y of each dot in one line: ");
    if (scanf("%f%f%f%f%f%f%f%f", &x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4))
    {
        if (linecross(x1,y1,x2,y2,x3,y3,x4,y4))
        {
            printf("Lines cross!!!");
        }
        else
        {
            printf("Lines dont cross!!!");
        }
    }
    else
    {
        printf("Wrong input!!!");
    }

    return 0;
}
