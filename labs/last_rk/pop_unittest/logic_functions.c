#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logic_functions.h"

int compare(const void* p, const void* q)
{
    const int *a = p;
    const int *b = q;
    return *a - *b;
}

int compare_char(const void* p, const void* q)
{
	node_t *pn = NULL, *qn = NULL;
	pn = (void *)p;
	qn = (void *)q;
	data_t *pd, *qd;
	pd = pn->data;
	qd = qn->data;
    return strcmp((char *)pd->name, (char *)qd->name);
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




node_t* find(node_t *head, const void *data, int (*cmp)(const void*, const void *))
{
    node_t *cur = NULL;

    for (cur = head; cur; cur = cur->next)
    {
    	if (cmp(cur, data) == 0)
            return cur;
    }
    return NULL;
}

data_t* pop_front(node_t **head) 
{
    node_t* prev = NULL;
    data_t* return_data;
    if (*head == NULL) {
        return NULL;
    }
    prev = (*head);
    return_data = prev->data;
    (*head) = (*head)->next;
    free(prev);
    return return_data;
}


void insert(node_t **head, node_t *elem, node_t *pr)
{
	node_t *cur, *prev = NULL;
    for (cur = *head; cur; cur = cur->next)
    {
        if (cur == pr)
        {
        	if (prev)
            {
            	prev->next = elem;
                elem->next = cur;
            }
            else
            {
                *head = elem;
                elem->next = cur;
            }
        }
        prev = cur;
    }
}


void remove_duplicates(node_t **head, int (*cmp)(const void*, const void*))
{
	node_t *cur, *prev, *cur_2, *start_2;
	start_2 = (*head);

	for (cur_2 = start_2; cur_2; cur_2 = cur_2->next)
	{    
		prev = cur_2;
		for (cur = cur_2->next; cur; cur = cur->next)
	    {
	    	if(cmp(cur_2, cur) == 0)
	    	{
	    		prev->next = cur->next;
	    	}
	    	else
	    		prev = cur;
	    }
	}
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
			head = head->next;
			i++;
		}
		(*back) = head->next;
		head->next = NULL;
	}
	else
	{
		while (i < (int)(n/2))
		{
			head = head->next;
			i++;
		}
		(*back) = head->next;
		head->next = NULL;
	}

}


node_t* sorted_merge(node_t **first_head, node_t **second_head, int (*cmp)(const void *, const void *))
{
	node_t *new = NULL, *start;
	start = *first_head;
	int flag = 0;

	while (*first_head)
	{

		while (*second_head)
		{
			
			if (cmp((*first_head), (*second_head)) <= 0)
			{
				flag = 1;
				
				if (!new)
					new = *first_head;
				else
				{
					new->next = *first_head;
					new = new->next;
				}
				(*first_head) = (*first_head)->next;
				if (*first_head == NULL)
					break;
			}
			else
			{
				if (!flag)
					start = *second_head;
				flag = 1;
				if (!new)
					new = *second_head;
				else
				{
					new->next = *second_head;
					new = new->next;
				}
				(*second_head) = (*second_head)->next;
			}
		}
		if ((*second_head) == NULL)
		{
			if (!new)
				new = *first_head;
			else
			{
				new->next = *first_head;
				new = new->next;
			}
			(*first_head) = (*first_head)->next;
		}
		else
		{
			if (!new)
				new = *second_head;
			else
			{
				new->next = *second_head;
				new = new->next;
			}
			(*second_head) = (*second_head)->next;
		}
	}

	new = start;
	return new;
}


void sort(node_t **head, int (*cmp)(const void *, const void *)) 
{
    int n = 0;
    node_t *top = NULL;
    apply(*head, count, &n);
    if (n <= 1) 
    {
    	return;
    }
    front_back_split((*head), &top);
    sort(&(*head), cmp);
    sort(&top, cmp);

    (*head) = sorted_merge(&(*head), &top, cmp);
}