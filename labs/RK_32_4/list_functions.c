#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_functions.h"


node_t* create_node(data_t *data) // создание указателя на узел
{
	node_t *node  = malloc(sizeof(node_t));

	if (node)
	{
		node->data = data;
		node->next = NULL;
	}
	return node;
}

data_t* create_data_node(char *person, char *group) // заполнение самого узла 
{
	data_t *data_node = malloc(sizeof(data_t));
	if (data_node)
	{
		data_node->name = person;
		data_node->group = group;
	}
	return data_node;
}


node_t* add_node(node_t *head, data_t *data)
{
    node_t *cur = head, *node;
    node = create_node(data);


    if (!head)
        return node;

    for ( ; cur->next; cur = cur->next)
        ;

    cur->next = node;

    return head;
}



node_t* create_list_of_groups(node_t **node, FILE *f, int *cnt) // создание списка из файла
{
	*cnt = 0;
	node_t *tmp;
	tmp = (*node);
	char *person = (char*)malloc(70);
	char *group = (char*)malloc(10);
	data_t *data_node;
	while (!feof(f))
	{
		person = (char*)malloc(70);
		group = (char*)malloc(10);
		fscanf(f, "%s%s", person,group);
		data_node = create_data_node(person,group);
		(*node) = add_node((*node),data_node);
		(*node) = (*node)->next;
		*cnt += 1;

	}
	(*node) = tmp;
	return (*node);
}

void print_node(node_t *node, void *arg)
{
    char *fmt = arg;
    printf(fmt, node->data->name, node->data->group);
}
