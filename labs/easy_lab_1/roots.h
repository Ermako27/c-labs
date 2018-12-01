#ifndef __ROOTS_H__
#define __ROOTS_H__

#include "integration.h"

#define EPS 0.01
#define STEP 0.0001

double find_root(func_t func_1, func_t func_2, double a, double b);

#endif // __ROOTS_H__
