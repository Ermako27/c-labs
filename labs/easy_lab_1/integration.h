#ifndef __INTEGRATION_H__
#define __INTEGRATION_H__

typedef double (*func_t)(double);


typedef double (*method_t)(double, double, int, func_t);


double integral(double a, double b, double eps, method_t meth, func_t func);
double trapezium(double a, double b, int n, func_t func);

#endif // __INTEGRATION_H__
