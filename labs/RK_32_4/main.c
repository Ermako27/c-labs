#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_functions.h"
#include "logic_functions.h"

#define TRUE 1



int main(int argc, char **argv)
{
	int menu = TRUE;
	FILE *f;
    FILE *o = fopen("o.txt", "w");
	char *person = (char*)malloc(70);
	char *group = (char*)malloc(10);
	node_t *head = NULL;
	node_t *tmp_node = NULL;
	node_t *find_node = NULL;
	data_t *data_node;
	data_t *poped_data;
    char num;

	char *name = (char*)malloc(20);
	char *new_name = (char*)malloc(70);
    char *new_group = (char*)malloc(70);

    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Could not open file\n");
        return 0;
    }


    if (fscanf(f, "%c", &num) != 1)
    {
        printf("Empty file\n");
        return 0;
    }

    rewind(f);
	fscanf(f, "%s%s", person,group);
    int count;
	data_node = create_data_node(person,group);
	head = add_node(head, data_node);
	head = create_list_of_groups(&head,f,&count);
    printf("%d\n", count);


	while (menu)
	{
		printf("\n");
		printf("--------------------------------------------------\n");
        printf("1 - Печать списка.                                |\n");
        printf("2 - Сгруппировать список.                         |\n");
        printf("3 - Добавить запись в список.                     |\n");
        printf("--------------------------------------------------\n");
        printf("\n\n>>>");

        if (scanf("%d", &menu) == 0 || menu > 9	 || menu < 0)
        {
            printf("Incorrect input!!!\n");
            break;
        }

        // if (menu == 1)
        // {
        // 	poped_data = pop_front(&head);
        //     if (poped_data == NULL)
        //     {
        //         printf("Список пуст!\n");
        //         continue;
        //     }
        // 	printf("Удаленные данные:\n");
        // 	printf("%s %s\n", "Название", "Длительность");
        // 	printf("%s %d\n", poped_data->name, poped_data->duration);

        // }

        // if (menu == 2) 
        // {
        // 	printf("Введите название фильма, перед которым добавить новую запись: ");
        //     name = (char*)malloc(20);
        //     scanf("%s", name);
        //     int duration = 0;

        //     data_node = create_data_node(name, duration);
        //     tmp_node = create_node(data_node);

        //     find_node = find(head, tmp_node, compare_char);
        //     if (!find_node)
        //     {
        //         printf("\nТакого фильма нет в списке!\n" );
        //         continue;
        //     }

        //     printf("Введите название и продолжительность фильма: ");
        //     new_name = (char*)malloc(20);
        //     scanf("%s %d", new_name, &duration);

            
        //     data_node = create_data_node(new_name, duration);
        //     tmp_node = create_node(data_node);
        //     insert(&head, tmp_node, find_node);
        
        	
        // }

        // if (menu == 3)
        // {
        //     printf("Введите название и продолжительность фильма: ");
        //     new_name = (char*)malloc(20);
        //     scanf("%s %d", new_name, &duration);
        //     data_node = create_data_node(new_name,duration);
        //     head = add_node(head, data_node);
        // }

        // if (menu == 4) 
        // {
        // 	printf("Список сортировуется по длительности\n");
        //     sort(&head, compare);
        //     printf("Список отсортирован!\n");
        	
        // }

        if (menu == 1)
        {
            printf("\n \t Список:\n");
            printf("%s %s\n\n", "Человек", "Группа");
            apply(head, print_node, "%10s %10s\n");
        }

        if (menu == 2)
        {
            printf("\n \t Список группируется!\n");
            sort(&head, compare_char);
            printf("\n Список сгруппировался!!!\n");
            // while (head != NULL)
            // {
            //     fprintf(o, "%s %s\n", head->data->name, head->data->group);
            //     head = head->next;
            // }

            for (;head; head = head -> next)
            {
                printf("%10s %10s\n", head->data->name, head->data->group);
                fprintf(o, "%10s %10s\n", head->data->name, head->data->group);
            }
            fclose(o);
        }

        if (menu == 3)
        {
            printf("Введите имя и группу: \n");
            new_name = (char*)malloc(70);
            new_group = (char*)malloc(70);
            scanf("%s%s", new_name, new_group);
            data_node = create_data_node(new_name,new_group);
            head = add_node(head, data_node);
        }

        // if (menu == 2)
        // {
        // 	printf("\n \t Список:\n");
        //     printf("%s %s\n\n", "Человек", "Группа");
        //     apply(head, print_node, "%10s %10d\n");
        // }

	} 

}