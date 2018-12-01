#ifndef __FUNCTIONS__H__

#define __FUNCTIONS__H__

void free_matrix_rows(float **data, int n);

float** allocate_matrix_rows(int n, int m, FILE *f);

int multiply(int n1, int m1, float *a[m1], int n2, int m2, float *b[m2], float *result[m2]);

float determ(float** Arr, int size, int m);

int sum(int n, int m, float a[], float b[], float **result);

int filtr(FILE *f);

void create_matrix(float* data, FILE *f);

float** alloc(int n, int m);

void print_matrix(int n, int m, float *a[m]);

void print_mass(float a[], int n,int m);


#endif
