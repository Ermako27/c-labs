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
    char *group;
};

// структура хранящая указатели
// на узлы с информацией

struct node 
{
	data_t *data;
	node_t *next;
};




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


void print_node(node_t *node, void *arg)
{
    char *fmt = arg;
    printf(fmt, node->data->name, node->data->group);
}

void apply(node_t *head,
             void (*f)(node_t*, void*),
                                    void *arg)
{
    for ( ; head; head = head->next)
        f(head, arg);
}

int compare_char(const void* p, const void* q)
{
	node_t *pn = NULL, *qn = NULL;
	pn = (void *)p;
	qn = (void *)q;
	data_t *pd, *qd;
	pd = pn->data;
	qd = qn->data;
    return strcmp((char *)pd->group, (char *)qd->group);
}


void front_back_split(node_t* head, node_t** back)
{
	int n = 0, i = 0;
	apply((head), count, &n);
	node_t *start;
	start = head;

	if (n % 2 == 0)
	{
		while (i < (int)(n/2) - 1)
		{
			(head) = (head)->next;
			i++;
		}
		(*back) = head->next;
		head->next = NULL;
	}
	else
	{
		while (i < (int)(n/2))
		{
			(head) = (head)->next;
			i++;
		}
		(*back) = head->next;
		head->next = NULL;
	}

}


node_t* sorted_merge(node_t **head_a, node_t **head_b,
	int (*comparator)(const void *, const void *))
{
	node_t *new = NULL, *start;// *node = NULL;
	start = *head_a;
	int flag = 0;

	while (*head_a)
	{
		while (*head_b)
		{
			if (comparator((*head_a), (*head_b)) <= 0)
			{
				flag = 1;
				
				if (!new)
					new = *head_a;
				else
				{
					new->next = *head_a;
					new = new->next;
				}
				(*head_a) = (*head_a)->next;
				if (*head_a == NULL)
					break;
			}
			else
			{
				if (!flag)
					start = *head_b;
				flag = 1;
				if (!new)
					new = *head_b;
				else
				{
					new->next = *head_b;
					new = new->next;
				}
				(*head_b) = (*head_b)->next;
			}
		}
		if ((*head_b) == NULL)
		{
			if (!new)
				new = *head_a;
			else
			{
				new->next = *head_a;
				new = new->next;
			}
			(*head_a) = (*head_a)->next;
		}
		else
		{
			if (!new)
				new = *head_b;
			else
			{
				new->next = *head_b;
				new = new->next;
			}
			(*head_b) = (*head_b)->next;
		}
	}

	new = start;
	return new;
}


void sort(node_t **head, 
	int (*comparator)(const void *, const void *)) 
{
    node_t *high = NULL;
    int n = 0;
    apply(*head, count, &n);
    if (n <= 1) 
    {
    	return;
    }
    front_back_split((*head), &high);
    sort(&(*head), comparator);
    sort(&high, comparator);

    (*head) = sorted_merge(&(*head), &high, comparator);
}







void test_sort(void)
{

	FILE *f1 = fopen("persons.txt", "r");
	char *name1 = (char*)malloc(70);
	char *group1 = (char*)malloc(10);
	node_t *head1 = NULL;
	data_t *data_node1;
	while (fscanf(f1, "%s%s", name1,group1) != EOF)
	{
		data_node1 = create_data_node(name1,group1);
		head1 = add_node(head1, data_node1);
		name1 = (char*)malloc(70);
	}


	printf("\n----------------TEST 1-----------------\n");
	printf("\nРазные факультеты, неупорядоченные данные. \n");
	printf("\nДо сортировки.\n");
	apply(head1, print_node, "%10s %10s\n");
	sort(&head1, compare_char);
	printf("\nПосле сортировки.\n");
	apply(head1, print_node, "%10s %10s\n");

////////////////////////////////////////////////////////////////

	FILE *f2 = fopen("persons1.txt", "r");
	char *name2 = (char*)malloc(70);
	char *group2 = (char*)malloc(10);
	node_t *head2 = NULL;
	data_t *data_node2;
	while(fscanf(f2, "%s%s", name2,group2) != EOF)
	{
		data_node2 = create_data_node(name2,group2);
		head2 = add_node(head2, data_node2);
		name2 = (char*)malloc(70);
	}


	printf("\n----------------TEST 2-----------------\n");
	printf("\nОдинаковые факультеты, неупорядоченные. \n");
	printf("\nДо сортировки.\n");
	apply(head2, print_node, "%10s %10s\n");
	sort(&head2, compare_char);
	printf("\nПосле сортировки.\n");
	apply(head2, print_node, "%10s %10s\n");
///////////////////////////////////////////////////////////////////////



	FILE *f3 = fopen("persons2.txt", "r");
	char *name3 = (char*)malloc(70);
	char *group3 = (char*)malloc(10);
	node_t *head3 = NULL;
	data_t *data_node3;
	while(fscanf(f3, "%s%s", name3,group3) != EOF)
	{
		data_node3 = create_data_node(name3,group3);
		head3 = add_node(head3, data_node3);
		name3 = (char*)malloc(20);
	}


	printf("\n----------------TEST 3-----------------\n");
	printf("\nИзначально упорядоченные данные. \n");
	printf("\nДо сортировки.\n");
	apply(head3, print_node, "%10s %10s\n");
	sort(&head3, compare_char);
	printf("\nПосле сортировки.\n");
	apply(head3, print_node, "%10s %10s\n");


}

int main(void)
{
	test_sort();
	return 0;
}