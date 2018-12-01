
#ifndef structures_h
#define structures_h

#include "structures.h"

#endif

#ifndef logic_functions_h
#define logic_functions_h

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare(const void* p, const void* q);

int compare_char(const void* p, const void* q);

void count(node_t *pers, void *arg);

void apply(node_t *head,
             void (*f)(node_t*, void*),
                                    void *arg);

node_t* find(node_t *head, const void *data, int (*cmp)(const void*, const void *));

data_t* pop_front(node_t **head);

void insert(node_t **head, node_t *elem, node_t *pr);

void remove_duplicates(node_t **head, int (*cmp)(const void*, const void*));

void front_back_split(node_t* head, node_t** back);

node_t* sorted_merge(node_t **head_a, node_t **head_b, int (*cmp)(const void *, const void *));

void sort(node_t **head, int (*cmp)(const void *, const void *)); 


#endif
