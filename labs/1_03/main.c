#include <stdio.h>
#define NO_NUM  -1


int process(FILE *f, int *count)
{
    *count = 0;
    int num;
    float prev_num, next_num;
    if (fscanf(f,"%f", &prev_num) == 1)
    {
        while (fscanf(f, "%d", &num) == 1)
        {
            next_num = num;
            if (next_num * prev_num < 0)
                *count += 1;
            prev_num = next_num;
        }
        return 0;
    }
    else
    {
        return NO_NUM;
    }
}

int main()
{
    int count;
    int p;
    printf("input values: ");
    p = process(stdin, &count);
    if (p == NO_NUM)
        printf("No numbers inputed");
    else
        printf("count of symbol change: %d", count);
    return 0;
}
