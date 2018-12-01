#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_functions.h"
#include "logic_functions.h"

#define TRUE 1



int main(void)
{
	int menu = TRUE;
	FILE *f = fopen("films.txt", "r");
	char *film = (char*)malloc(20);
	int duration;
	node_t *head = NULL;
	node_t *tmp_node = NULL;
	node_t *find_node = NULL;
	data_t *data_node;
	data_t *poped_data;

	char *name = (char*)malloc(20);
	char *new_name = (char*)malloc(20);

	fscanf(f, "%s%d", film,&duration);

	data_node = create_data_node(film,duration);
	head = add_node(head, data_node);
	head = create_list_of_films(&head,f);

	while (menu)
	{
		printf("\n");
		printf("--------------------------------------------------\n");
        printf("1 - Удалить элемент из начала списка.            |\n");
        printf("2 - Вставить новый элемент перед другим(insert). |\n");
        printf("3 - Создать новый элемент.                       |\n");
        printf("4 - Сортировка списка.                           |\n");
        printf("5 - Удаление дубликатов.                         |\n");
        printf("6 - Печать списка.                               |\n");
        printf("--------------------------------------------------\n");
        printf("\n\n>>>");

        if (scanf("%d", &menu) == 0 || menu > 9	 || menu < 0)
        {
            printf("Incorrect input!!!\n");
            break;
        }

        if (menu == 1)
        {
        	poped_data = pop_front(&head);
            if (poped_data == NULL)
            {
                printf("Список пуст!\n");
                continue;
            }
        	printf("Удаленные данные:\n");
        	printf("%s %s\n", "Название", "Длительность");
        	printf("%s %d\n", poped_data->name, poped_data->duration);

        }

        if (menu == 2) 
        {
        	printf("Введите название фильма, перед которым добавить новую запись: ");
            name = (char*)malloc(20);
            scanf("%s", name);
            int duration = 0;

            data_node = create_data_node(name, duration);
            tmp_node = create_node(data_node);

            find_node = find(head, tmp_node, compare_char);
            if (!find_node)
            {
                printf("\nТакого фильма нет в списке!\n" );
                continue;
            }

            printf("Введите название и продолжительность фильма: ");
            new_name = (char*)malloc(20);
            scanf("%s %d", new_name, &duration);

            
            data_node = create_data_node(new_name, duration);
            tmp_node = create_node(data_node);
            insert(&head, tmp_node, find_node);
        
        	
        }

        if (menu == 3)
        {
            printf("Введите название и продолжительность фильма: ");
            new_name = (char*)malloc(20);
            scanf("%s %d", new_name, &duration);
            data_node = create_data_node(new_name,duration);
            head = add_node(head, data_node);
        }

        if (menu == 4) 
        {
        	printf("Список сортировуется по длительности\n");
            sort(&head, compare);
            printf("Список отсортирован!\n");
        	
        }

        if (menu == 5)
        {
        	printf("Удаление повторений по названию.\n");
            remove_duplicates(&head, compare_char);
        }

        if (menu == 6)
        {
        	printf("\n \t Список:\n");
            printf("%s %s\n\n", "Название", "Длительность");
            apply(head, print_node, "%10s %10d\n");
        }

	} 

}