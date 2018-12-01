#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logic_functions.h"
#include "list_functions.h"

void test_pop(void)
{
	FILE *f = fopen("test.txt", "r");
	char *film1 = (char*)malloc(20);
	char *film2 = (char*)malloc(20);
	char *film3 = (char*)malloc(20);
	int duration = 0;
	node_t *head = NULL;
	data_t *data_node, *poped_data;

	fscanf(f, "%s%d", film1,&duration);
	data_node = create_data_node(film1,duration);
	head = add_node(head, data_node);
	fscanf(f, "%s%d", film2,&duration);
	data_node = create_data_node(film2,duration);
	head = add_node(head, data_node);
	fscanf(f, "%s%d", film3,&duration);
	data_node = create_data_node(film3,duration);
	head = add_node(head, data_node);	

	printf("\n----------РАБОТОСПОСОБНОСТЬ-------------\n");

	printf("Перед удалением: \n");
	apply(head, print_node, "%10s %10d\n");
	printf("----------------------\n");
	poped_data = pop_front(&head);
	printf("Удаленные данные:\n");
	printf("%s %d\n", poped_data->name, poped_data->duration);
	printf("----------------------\n");
	poped_data = pop_front(&head);
	printf("Удаленные данные:\n");
	printf("%s %d\n", poped_data->name, poped_data->duration);
	printf("После удаления:\n");
	apply(head, print_node, "%10s %10d\n\n\n");


	printf("\n-------УДАЛЕНИЕ ИЗ ПУСТОГО СПИСКА--------\n");

	printf("Перед удалением: \n");
	apply(head, print_node, "%10s %10d\n");
	printf("----------------------\n");
	poped_data = pop_front(&head);
	printf("Удаленные данные:\n");
	printf("%s %d\n", poped_data->name, poped_data->duration);
	printf("----------------------\n");
	poped_data = pop_front(&head);
	if (poped_data == NULL)
		printf("Список пуст!\n");

}

int main(void)
{
	test_pop();
	return 0;
}