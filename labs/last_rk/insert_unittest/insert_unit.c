#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logic_functions.h"
#include "list_functions.h"

void test_insert(void)
{
	FILE *f = fopen("films.txt", "r");
	char *film = (char*)malloc(20);
	int duration;
	node_t *head = NULL;
	node_t *tmp_node = NULL;
	node_t *find_node = NULL;
	data_t *data_node;
	fscanf(f, "%s%d", film,&duration);
	data_node = create_data_node(film,duration);
	head = add_node(head, data_node);
	head = create_list_of_films(&head,f);


	printf("\n----------ВСТАВКА ПЕРЕД ПЕРВЫМ И ПОСЛЕДНИМ---------\n");
	printf("Перед вставкой: \n");
	apply(head, print_node, "%10s %10d\n");
	


	char *name1 = "ono";
    duration = 0;

    data_node = create_data_node(name1, duration);
    tmp_node = create_node(data_node);

    find_node = find(head, tmp_node, compare_char);
    if (!find_node)
    {
   		printf("\nТакого фильма нет в списке!\n" );
    }

    
    char *new_name1 = "privet";
    duration = 100;
    
            
    data_node = create_data_node(new_name1, duration);
    tmp_node = create_node(data_node);
    insert(&head, tmp_node, find_node);

/////////////////////////////////////////////////

    char *name2 = "pobeg";
    duration = 0;

    data_node = create_data_node(name2, duration);
    tmp_node = create_node(data_node);

    find_node = find(head, tmp_node, compare_char);
    if (!find_node)
    {
   		printf("\nТакого фильма нет в списке!\n" );
    }

    
    char *new_name2 = "poka";
    duration = 300;
    
            
    data_node = create_data_node(new_name2, duration);
    tmp_node = create_node(data_node);
    insert(&head, tmp_node, find_node);

    printf("\n");
    printf("После вставки:\n");
    apply(head, print_node, "%10s %10d\n");


    printf("\n------------ВСТАВКА ПЕРЕД НЕСУЩЕСТВУЮЩИМ------------\n");

    printf("Перед вставкой: \n");
	apply(head, print_node, "%10s %10d\n");
	

	
	char *name3 = "none";
	printf("\nФильм, перед которым мы хотим вставить запись: %s\n", name3);
    duration = 0;

    data_node = create_data_node(name3, duration);
    tmp_node = create_node(data_node);

    find_node = find(head, tmp_node, compare_char);
    if (!find_node)
    {
   		printf("\nТакого фильма нет в списке!\n" );
    }

    
    // char *new_name1 = "privet";
    // duration = 100;
    
            
    // data_node = create_data_node(new_name1, duration);
    // tmp_node = create_node(data_node);
    // insert(&head, tmp_node, find_node);	

}

int main(void)
{
	test_insert();
	return 0;
}