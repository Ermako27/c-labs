/*
test_01.c íî ñ typedef
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SEARCH_NAME "Sidorov"


typedef struct person person_t;
typedef struct data data_t;


struct person
{
    char *name;
    int born_year;
    data_t *cur;
    data_t *next;
};

struct data
{
    char *name;
    int duation; 
};


/*
// À íå:

typedef struct person
{
    char *name;
    int born_year;

    struct person *next;
	
} person_t;
*/


person_t* create_person(char *name, int born_year)
{
    person_t *pers = malloc(sizeof(person_t));

    if (pers)
    {
        pers->name = name;
        pers->born_year = born_year;
        pers->next = NULL;        
    }
        
    return pers;
}


person_t* add_front(person_t *head, person_t *pers)
{
    pers->next = head;
    return pers;
}


person_t* add_end(person_t *head, person_t *pers)
{
    person_t *cur = head;

    if (!head)
        return pers;

    for ( ; cur->next; cur = cur->next)
        ;

    cur->next = pers;

    return head;
}


person_t* lookup(person_t *head, const char *name)
{
    for ( ; head; head = head->next)
        if (strcmp(head->name, name) == 0)
            return head;

    return NULL;
}


void apply(person_t *head,
             void (*f)(person_t*, void*),
                                    void *arg)
{
    for ( ; head; head = head->next)
        f(head, arg);
}


void print_person(person_t *pers, void *arg)
{
    char *fmt = arg;

    printf(fmt, pers->name, pers->born_year);
}


void count(person_t *pers, void *arg)
{
    int *counter = arg;

    (*counter)++;
}


void free_all(person_t *head)
{
    person_t *next;

    for ( ; head; head = next)
    {
        next = head->next;
        free(head);
    }
}


person_t* del_by_name(person_t *head, const char *name)
{
    person_t *cur, *prev = NULL;

    for (cur = head; cur; cur = cur->next)
    {
        if (strcmp(cur->name, name) == 0)
        {
            if (prev)
                prev->next = cur->next;
            else
                head = cur->next;

            free(cur);

            return  head;
        }

        prev = cur;
    }

    return NULL;
}


int main(void)
{
    person_t *head = NULL;
    person_t *node;
    int n = 0;

    // NB: "Ivanov" - ñòðîêîâûé ëèòåðàë, ò.å. ñòðîêîâàÿ êîíñòàíòà
    node = create_person("Ivanov", 1995);
    assert(node);
    head = add_front(head, node);

    node = create_person(SEARCH_NAME, 1994);
    assert(node);
    head = add_front(head, node);

    node = create_person("Petrov", 1995);
    assert(node);
    head = add_front(head, node);

    apply(head, print_person, "%s %d\n");

    printf("\n");

    node = create_person("Vasechkin", 1996);
    assert(node);
    head = add_end(head, node);

    apply(head, print_person, "%s %d\n");

    printf("\n");

    apply(head, count, &n);

    printf("List contains %d element(s)\n", n);

    node = lookup(head, SEARCH_NAME);

    printf("%s is in %p element\n", SEARCH_NAME, node);

    head = del_by_name(head, SEARCH_NAME);

    node = lookup(head, SEARCH_NAME);

    printf("%s is in %p element\n", SEARCH_NAME, node);

    free_all(head);

    return 0;
}