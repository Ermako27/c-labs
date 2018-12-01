#ifndef __FUNCTIONS__H__

#define __FUNCTIONS__H__

void print_mass(float a[], int size);

int array_count(FILE *f, int *n);

void array_create(float* data, FILE *f);

int filtr_count(FILE *f, int *n, float *s);

void array_create_f(float* data, FILE *f, float sum);

void sort(void *pbase, size_t total, size_t size, int (*compare)(const void*, const void*));

int compare(const void* p, const void* q);

unsigned long long tick(void);

#endif
