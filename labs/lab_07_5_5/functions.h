#ifndef __FUNCTIONS__H__

#define __FUNCTIONS__H__
void print_mass(float a[], int size);
int array_count(FILE *f, float **data, int *n);
void array_create(float* data, FILE *f);
int filtr_count(FILE *f, float **data, int *n);
void array_create_f(float* data, FILE *f);
int sort(float* data, int n);

#endif // FUNCTIONS_H
