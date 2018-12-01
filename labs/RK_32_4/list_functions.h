
#ifndef structures_h
#define structures_h

#include "structures.h"

#endif

#ifndef list_functions_h
#define list_functions_h

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node_t* create_node(data_t *data); // создание указателя на узел

data_t* create_data_node(char *person, char *group); // заполнение самого узла 

node_t* add_node(node_t *head, data_t *data);

node_t* create_list_of_groups(node_t **node, FILE *f, int *cnt); // создание списка из файла

void print_node(node_t *node, void *arg);

#endif
