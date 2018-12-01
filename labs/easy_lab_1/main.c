#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "integration.h"
#include "roots.h"
#include "functions.h"


#define A -10
#define B 10


int main(void)
{
    
 	
	double root_l1 = find_root(line, exp_1, A, B);
	double root_l2 = find_root(line, exp_2, A, B);
	double root_12 = find_root(exp_1, exp_2, A, B);
		
	double s1 = integral(root_l2, root_l1, 0.001, trapezium, line);
	double s2 = integral(root_l2, root_l1, 0.001, trapezium, exp_2);
	double s3 = integral(root_l1, root_12, 0.001, trapezium, exp_1);
	double s4 = integral(root_l1, root_12, 0.001, trapezium, exp_2); 
	
	double s = s1 - s2 + s3 - s4;

	printf("\n square of triangle is: %f\n", s);	
	
    return 0;
}

