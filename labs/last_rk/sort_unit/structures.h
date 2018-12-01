#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node_t;
typedef struct data data_t;

// структура с информацией

struct data
{
    char *name;
    int duration; 
};
// структура хранящая указатели
// на узлы с информацией

struct node 
{
	data_t *data;
	node_t *next;
};