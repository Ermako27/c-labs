#ifndef __FUNCTIONS__H__

#define __FUNCTIONS__H__
 
#define PRINT_API __attribute__ ((__visibility__("default")))

int data_copy(int *data1, int **data2, int n, int key);

int simple_numbers(int **data, int n);

#endif