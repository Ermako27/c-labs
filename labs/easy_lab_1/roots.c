#include <stdio.h>
#include "roots.h"
#include <math.h>

double find_root(func_t func_1, func_t func_2, double a, double b)
{
    double eps = EPS;
    double step = STEP;
    double x = a, y1 = func_1(a), y2 = func_2(a);
    double diff = y1 - y2;
    
    while ( fabs(diff) >= eps)
    {
    	x += step;
        y1 = func_1(x);
        y2 = func_2(x);
        
        diff = y1 - y2;
        
        
        if (x >= b) 
        {
            break;
        }
    }
    
    return x;
}