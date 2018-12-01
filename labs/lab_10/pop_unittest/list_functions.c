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

data_t* create_data_node(char *film, int duration) // заполнение самого узла 
{
	data_t *data_node = malloc(sizeof(data_t));

	if (data_node)
	{
		data_node->name = film;
		data_node->duration = duration;
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



node_t* create_list_of_films(node_t **node, FILE *f) // создание списка из файла
{
	node_t *tmp;
	tmp = (*node);
	char *film = (char*)malloc(20);
	int duration;
	data_t *data_node;
	while (!feof(f))
	{
		film = (char*)malloc(20);
		fscanf(f, "%s%d", film,&duration);
		//printf("8\n");
		data_node = create_data_node(film,duration);

		//printf("9\n");
		(*node) = add_node((*node),data_node);
		//printf("7\n");
		//printf("%s %d\n", node->data->name, node->data->duration);
		(*node) = (*node)->next;
		//printf("%s %d\n", node->data->name, node->data->duration);
	}
	(*node) = tmp;
	return (*node);
}

// void count(node_t *pers, void *arg)
// {
//     int *counter = arg;

//     (*counter)++;
// }

// void apply(node_t *head,
//              void (*f)(node_t*, void*),
//                                     void *arg) // печать списка
// {
//     for ( ; head; head = head->next)
//         f(head, arg);
// }

void print_node(node_t *node, void *arg)
{
    char *fmt = arg;
    printf(fmt, node->data->name, node->data->duration);
}
