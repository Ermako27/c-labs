#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logic_functions.h"

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

void count(node_t *pers, void *arg)
{
    int *counter = arg;

    (*counter)++;
}

void apply(node_t *head,
             void (*f)(node_t*, void*),
                                    void *arg)
{
    for ( ; head; head = head->next)
        f(head, arg);
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
