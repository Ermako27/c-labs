#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logic_functions.h"
#include "list_functions.h"

void test_sort(void)
{

	FILE *f1 = fopen("films1.txt", "r");
	char *film1 = (char*)malloc(20);
	int duration1 = 0;
	node_t *head1 = NULL;
	data_t *data_node1;
	while (fscanf(f1, "%s%d", film1,&duration1) != EOF)
	{
		data_node1 = create_data_node(film1,duration1);
		head1 = add_node(head1, data_node1);
		film1 = (char*)malloc(20);
	}


	printf("\n----------------TEST 1-----------------\n");
	printf("\nДанные в  обратном порядке. \n");
	printf("\nДо сортировки.\n");
	apply(head1, print_node, "%10s %10d\n");
	sort(&head1, compare);
	printf("\nПосле сортировки.\n");
	apply(head1, print_node, "%10s %10d\n");




	FILE *f2 = fopen("films2.txt", "r");
	char *film2 = (char*)malloc(20);
	int duration2;
	node_t *head2 = NULL;
	data_t *data_node2;
	while(fscanf(f2, "%s%d", film2,&duration2) != EOF)
	{
		data_node2 = create_data_node(film2,duration2);
		head2 = add_node(head2, data_node2);
		film2 = (char*)malloc(20);
	}


	printf("\n----------------TEST 2-----------------\n");
	printf("\nДанные в случайном порядке. \n");
	printf("\nДо сортировки.\n");
	apply(head2, print_node, "%10s %10d\n");
	sort(&head2, compare);
	printf("\nПосле сортировки.\n");
	apply(head2, print_node, "%10s %10d\n");




	FILE *f3 = fopen("films3.txt", "r");
	char *film3 = (char*)malloc(20);
	int duration3;
	node_t *head3 = NULL;
	data_t *data_node3;
	while(fscanf(f3, "%s%d", film3,&duration3) != EOF)
	{
		data_node3 = create_data_node(film3,duration3);
		head3 = add_node(head3, data_node3);
		film3 = (char*)malloc(20);
	}


	printf("\n----------------TEST 3-----------------\n");
	printf("\nИзначально упорядоченные данные. \n");
	printf("\nДо сортировки.\n");
	apply(head3, print_node, "%10s %10d\n");
	sort(&head3, compare);
	printf("\nПосле сортировки.\n");
	apply(head3, print_node, "%10s %10d\n");





	FILE *f4 = fopen("films4.txt", "r");
	char *film4 = (char*)malloc(20);
	int duration4;
	node_t *head4 = NULL;
	data_t *data_node4;
	while(fscanf(f4, "%s%d", film4,&duration4) != EOF)
	{
		data_node4 = create_data_node(film4,duration4);
		head4 = add_node(head4, data_node4);
		film4 = (char*)malloc(20);
	}


	printf("\n----------------TEST 4-----------------\n");
	printf("\nСортировка по названию.\n");
	printf("\nДо сортировки.\n");
	apply(head4, print_node, "%10s %10d\n");
	sort(&head4, compare_char);
	printf("\nПосле сортировки.\n");
	apply(head4, print_node, "%10s %10d\n");


}

int main(void)
{
	test_sort();
	return 0;
}