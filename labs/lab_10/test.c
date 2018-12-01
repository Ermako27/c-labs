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


// node_t* add_node(node_t *node, data_t *data)
// {
// 	printf("1\n");
// 	node_t *new_node = create_node(data);
// 	printf("2\n");
// 	node->next = new_node;
// 	printf("3\n");
// 	return node;
// }

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



node_t* create_list_of_films(node_t **node, FILE *f)
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


void apply(node_t *head,
             void (*f)(node_t*, void*),
                                    void *arg)
{
    for ( ; head; head = head->next)
        f(head, arg);
}


// void print_node(node_t *head, void *arg)
// {
//     char *fmt = arg;
//     char *name;
//     int duration;
//     name = (char *) malloc (20);
//     data_t *data_node = NULL;
//     data_node = head->data;
//     name = data_node->name;
//     duration = data_node->duration;
//     printf(fmt, name, duration);
// }



// void apply(node_t *head,
//              void (*f)(node_t*, void*),
//                                     void *arg)
// {
// 	printf("1\n");
//     for ( ; head; head = head->next)
//     {
//         f(head, arg);
//     }
// }


void print_node(node_t *node, void *arg)
{
    char *fmt = arg;
    printf(fmt, node->data->name, node->data->duration);
}

int main(void)
{
	FILE *f = fopen("films.txt", "r");

	char *film = (char*)malloc(20);
	int duration;
	node_t *head = NULL;
	data_t *data_node;
	// data_node = create_data_node("start",123450);
	// head = add_node(head, data_node);
	fscanf(f, "%s%d", film,&duration);
	//printf("%s %d\n", film,duration);
	data_node = create_data_node(film,duration);
	head = add_node(head, data_node);
	head = create_list_of_films(&head,f);
	//printf("1\n");
	// while (!feof(f))
	// {
	// 	film = (char*)malloc(20);
	// 	fscanf(f,"%s%d", film,&duration);
	// 	printf("film: %s\n", film);
	// 	printf("duration: %d\n", duration);
	// }

	//printf("%s %d\n", head->data->name, head->data->duration);

	apply(head, print_node, "%s %d\n");


}


