#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TRUE 1



typedef struct _Node 
{
    int value;
    struct _Node *next;
    struct _Node *prev; 
} Node;

typedef struct DblLinkedList 
{
    int size;
    Node *head;
    Node *tail;
} DblLinkedList;


DblLinkedList* createDblLinkedList() 
{
    DblLinkedList *tmp = (DblLinkedList*) malloc(sizeof(DblLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
 
    return tmp;
}


Node* getNth(DblLinkedList *list, size_t index) {
    Node *tmp = list->head;
    size_t i = 0;
 
    while (tmp && i < index) {
        tmp = tmp->next;
        i++;
    }
 
    return tmp;
}


Node* getNthq(DblLinkedList *list, size_t index) {
    Node *tmp = NULL;
    size_t i;
     
    if (index < list->size/2) {
        i = 0;
        tmp = list->head;
        while (tmp && i < index) {
            tmp = tmp->next;
            i++;
        }
    } else {
        i = list->size - 1;
        tmp = list->tail;
        while (tmp && i > index) {
            tmp = tmp->prev;
            i--;
        }
    }
 
    return tmp;
}




//////////////////////////////////////////////////////////////////



// void pushFront(DblLinkedList *list, void *data) {
//     Node *tmp = (Node*) malloc(sizeof(Node));
//     if (tmp == NULL) {
//         exit(1);
//     }
//     tmp->value = data;
//     tmp->next = list->head;
//     tmp->prev = NULL;
//     if (list->head) {
//         list->head->prev = tmp;
//     }
//     list->head = tmp;
 
//     if (list->tail == NULL) {
//         list->tail = tmp;
//     }
//     list->size++;
// }


// void* popFront(DblLinkedList *list) {
//     Node *prev;
//     void *tmp;
//     if (list->head == NULL) {
//         exit(2);
//     }
 
//     prev = list->head;
//     list->head = list->head->next;
//     if (list->head) {
//         list->head->prev = NULL;
//     }
//     if (prev == list->tail) {
//         list->tail = NULL;
//     }
//     tmp = prev->value;
//     free(prev);
 
//     list->size--;
// }


///////////////////////////////////////////////////////////////////////////////////////



void pushBack(DblLinkedList *list, int value) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(3);
    }
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;
 
    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
}


// void* popBack(DblLinkedList *list) {
//     Node *next;
//     void *tmp;
//     if (list->tail == NULL) {
//         exit(4);
//     }
 
//     next = list->tail;
//     list->tail = list->tail->prev;
//     if (list->tail) {
//         list->tail->next = NULL;
//     }
//     if (next == list->head) {
//         list->head = NULL;
//     }
//     tmp = next->value;
//     free(next);
 
//     list->size--;
//     return tmp;
// }

///////////////////////////////////////////////////////////////////////////


// void insert(DblLinkedList *list, size_t index, void *value)
// {
//     Node *elm = NULL;
//     Node *ins = NULL;
//     elm = getNth(list, index);
//     if (elm == NULL) 
//     {
//         // pushFront(list,value);
//         printf("!!!\n");
//     }

//     else 
//     {
//         ins = (Node*) malloc(sizeof(Node));
//         ins->value = value;
//         ins->prev = elm;
//         ins->next = elm->next;
//         if (elm->next) {
//             elm->next->prev = ins;
//         }
//         elm->next = ins;
 
//         if (!elm->prev) {
//             list->head = elm;
//         }
//         if (!elm->next) {
//             list->tail = elm;
//         }
 
//         list->size++;
//     }
// }
 
// void* deleteNth(DblLinkedList *list, size_t index) {
//     Node *elm = NULL;
//     void *tmp = NULL;
//     elm = getNth(list, index);
//     if (elm == NULL) {
//         exit(5);
//     }
//     if (elm->prev) {
//         elm->prev->next = elm->next;
//     }
//     if (elm->next) {
//         elm->next->prev = elm->prev;
//     }
//     tmp = elm->value;
 
//     if (!elm->prev) {
//         list->head = elm->next;
//     }
//     if (!elm->next) {
//         list->tail = elm->prev;
//     }
 
//     free(elm);
 
//     list->size--;
 
//     return tmp;
// }


//////////////////////////////////////////////////////////////////////////////////

void printInt(int value) {
    printf("%d ", value);
}


void printDblLinkedList(DblLinkedList *list, void (*printInt)(void*)) {
    Node *tmp = list->head;
    while (tmp) {
        printInt(tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}


////////////////////////////////////////////////////////////////////////////////////////

int cmp(void* p, void* q)
{
   const float *a = p;
   const float *b = q;
   return *a - *b;
}



void insertBeforeElement(DblLinkedList *list, Node* elm, void *value) {
    Node *ins = NULL;
    if (elm == NULL) {
        exit(6);
    }
     
    if (!elm->prev) {
        pushFront(list, value);
        return;
    }
    ins = (Node*) malloc(sizeof(Node));
    ins->value = value;
    ins->prev = elm->prev;
    elm->prev->next = ins;
    ins->next = elm;
    elm->prev = ins;
 
    list->size++;
}


void insertionSort(DblLinkedList **list, int (*cmp)(void*, void*)) {
    DblLinkedList *out = createDblLinkedList();
    Node *sorted = NULL;
    Node *unsorted = NULL;
     
    pushFront(out, popFront(*list));

    unsorted = (*list)->head;
    while (unsorted) {
        sorted = out->head;      
        while (sorted && !cmp(unsorted->value, sorted->value)) {
            sorted = sorted->next;
        }
        if (sorted) {
            insertBeforeElement(out, sorted, unsorted->value);
        } else {
            pushBack(out, unsorted->value);
        }
        unsorted = unsorted->next;
    }
 
    free(*list);
    *list = out;
}




int main(void) 
{
 int menu = TRUE;
 DblLinkedList *list = createDblLinkedList();
 char enter;
 int a,b,c, value, index;


 printf("Введите значение: ");
 
 pushBack(list,&value);


 printf("Введите значение: ");
 scanf("%d", &value);
 pushBack(list,&value);


 printf("Введите значение: ");
 scanf("%d", &value);
 pushBack(list,&value);


 printDblLinkedList(list,printInt);



 // while (menu)
 // {
 //    printf("Введите команду: \n");
 //    scanf("%d", &menu);
 //    if (menu == 1)
 //    {
 //        printf("Введите элемент: ");
 //        scanf("%d", &value);
 //        pushBack(list,&value);
 //    }

 //    if (menu == 2)
 //    {
 //        printDblLinkedList(list, printInt);
 //    }

 // }

 return 0;


}