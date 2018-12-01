#include <stdio.h>
#include <stdlib.h>


#define TRUE 1


typedef struct list
{
  int field; // поле данных
  struct list *next; // указатель на следующий элемент
  struct list *prev; // указатель на предыдущий элемент
} dlist;


typedef struct _Node {
    void *value;
    struct _Node *next;
    struct _Node *prev; 
} Node;


typedef struct _DblLinkedList {
    size_t size;
    Node *head;
    Node *tail;
} DblLinkedList;



dlist * init(int a)  // а- значение первого узла
{
  dlist *lst;
  // выделение памяти под корень списка
  lst = (dlist*)malloc(sizeof(dlist));
  lst->field = a;
  lst->next = NULL; // указатель на следующий узел
  lst->prev = NULL; // указатель на предыдущий узел
  return(lst);
}


dlist * addelem(dlist *lst, int number)
{
  dlist *temp, *p;
  temp = (dlist*)malloc(sizeof(dlist));
  p = lst->next; // сохранение указателя на следующий узел
  lst->next = temp; // предыдущий узел указывает на создаваемый
  temp->field = number; // сохранение поля данных добавляемого узла
  temp->next = p; // созданный узел указывает на следующий узел
  temp->prev = lst; // созданный узел указывает на предыдущий узел
  if (p != NULL)
    p->prev = temp;
  return(temp);
}


DblLinkedList* createDblLinkedList() {
    DblLinkedList *tmp = (DblLinkedList*) malloc(sizeof(DblLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
 
    return tmp;
}


void deleteDblLinkedList(DblLinkedList **list) {
    Node *tmp = (*list)->head;
    Node *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
}


void pushFront(DblLinkedList *list, void *data) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(1);
    }
    tmp->value = data;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;
 
    if (list->tail == NULL) {
        list->tail = tmp;
    }
    list->size++;
}


    

void* popFront(DblLinkedList *list) {
    Node *prev;
    void *tmp;
    if (list->head == NULL) {
        exit(2);
    }
 
    prev = list->head;
    list->head = list->head->next;
    if (list->head) {
        list->head->prev = NULL;
    }
    if (prev == list->tail) {
        list->tail = NULL;
    }
    tmp = prev->value;
    free(prev);
 
    list->size--;
    return tmp;
}



void pushBack(DblLinkedList *list, int *value) {
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

void* popBack(DblLinkedList *list) {
    Node *next;
    void *tmp;
    if (list->tail == NULL) {
        exit(4);
    }
 
    next = list->tail;
    list->tail = list->tail->prev;
    if (list->tail) {
        list->tail->next = NULL;
    }
    if (next == list->head) {
        list->head = NULL;
    }
    tmp = next->value;
    free(next);
 
    list->size--;
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


void insert(DblLinkedList *list, size_t index, void *value) {
    Node *elm = NULL;
    Node *ins = NULL;
    elm = getNth(list, index);
    if (elm == NULL) {
        exit(5);
    }
    ins = (Node*) malloc(sizeof(Node));
    ins->value = value;
    ins->prev = elm;
    ins->next = elm->next;
    if (elm->next) {
        elm->next->prev = ins;
    }
    elm->next = ins;
 
    if (!elm->prev) {
        list->head = elm;
    }
    if (!elm->next) {
        list->tail = elm;
    }
 
    list->size++;
}
 
void* deleteNth(DblLinkedList *list, size_t index) {
    Node *elm = NULL;
    void *tmp = NULL;
    elm = getNth(list, index);
    if (elm == NULL) {
        exit(5);
    }
    if (elm->prev) {
        elm->prev->next = elm->next;
    }
    if (elm->next) {
        elm->next->prev = elm->prev;
    }
    tmp = elm->value;
 
    if (!elm->prev) {
        list->head = elm->next;
    }
    if (!elm->next) {
        list->tail = elm->prev;
    }
 
    free(elm);
 
    list->size--;
 
    return tmp;
}


void printDblLinkedList(DblLinkedList *list, void (*fun)(void*)) {
    Node *tmp = list->head;
    while (tmp) {
        fun(tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}


void printInt(void *value) {
    printf("%d ", *((int*) value));
}


int compare(void* p, void* q)
{
   const int *a = p;
   const int *b = q;
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
        // printf("1\n");
        sorted = out->head;     
        while (sorted && !cmp(unsorted->value, sorted->value)) {
            // printf("unsorted: %d sorted: %d", *(int*)unsorted->value, *(int*)sorted->value);
            sorted = sorted->next;
        }
        if (sorted) {
            // printf("3\n");
            // printf("unsorted: %d sorted: %d", *(int*)unsorted->value, *(int*)sorted->value);
            insertBeforeElement(out, sorted, unsorted->value);
        } else {
            // printf("4\n");
            pushBack(out, unsorted->value);
        }
        unsorted = unsorted->next;
    }
 
    free(*list);
    *list = out;
}


void sort(dlist *start)
{
    dlist *tmp;
    dlist *a;
    int t=0;
    int flag=1;
    while(flag==1)
    {
        tmp=start;
        a=tmp->next;
        flag=0;
        while(a)
        {
            if((tmp->field)>(a->field))
            {
                t=tmp->field;
                tmp->field=a->field;
                a->field=t;
                flag=1;
            }
            tmp=tmp->next;
            a=a->next;
        }
    }
}


void listprint(dlist *lst)
{
  dlist *p;
  p = lst;
  do {
    printf("%d |", p->field); // вывод значения элемента p
    p = p->next; // переход к следующему узлу
  } while (p != NULL); // условие окончания обхода
}

dlist * deletelem(dlist *lst)
{
  dlist *prev, *next;
  prev = lst->prev; // узел, предшествующий lst
  next = lst->next; // узел, следующий за lst
  if (prev != NULL)
    prev->next = lst->next; // переставляем указатель
  if (next != NULL)
    next->prev = lst->prev; // переставляем указатель
  free(lst); // освобождаем память удаляемого элемента
  return(prev);
}
    

void main(void) 
{
    dlist *p;
    
    dlist *lst;
      // выделение памяти под корень списка
    lst = (dlist*)malloc(sizeof(dlist));
    lst->next = NULL; // указатель на следующий узел
    lst->prev = NULL; // указатель на предыдущий узел
    
    int flag = 0;
    int count = 0;
	int menu = TRUE;
	DblLinkedList *list = createDblLinkedList();
	char enter;
	int index;
    int values[200];
	int *ptr_values[200];
    int t = 0;
	while (menu)
	{
        printf("1 - Добавить элемент в конец списка.\n");
        printf("2 - Добавить элемент в начало списка.\n");
        printf("3 - Вставить элемент в нужное место списка.\n");
        printf("4 - Удалить элемент.\n");
        printf("5 - Сортировка списка.\n");
        printf("6 - Печать списка.\n");
        printf("0 - завершение работы");
        printf("\n\n>>>");

        if (scanf("%d", &menu) == 0 || menu > 6	 || menu < 0)
        {
            printf("Incorrect input!!!\n");
            break;
        }

        if (menu == 1)
        {
        	// enter = getchar();
        	printf("Введите элемент: ");
        	scanf("%d", &values[t]);
            ptr_values[t] = &values[t];
        	pushBack(list, ptr_values[t]);
            t++;
            count++;

        }

        if (menu == 2)
        {
        	// enter = getchar();
            printf("Введите элемент: ");
            scanf("%d", &values[t]);
            ptr_values[t] = &values[t];
        	pushFront(list, ptr_values[t]);
            t++;
            count++;
        }

        if (menu == 3)
        {
        	// enter = getchar();
        	printf("Данная команда не позволяет вставить элемент на 1 позицию.\n");
        	printf("Нумерация начинается с 1.\n");
        	printf("Введите позицию: ");
        	scanf("%d", &index);
            printf("Введите элемент: ");
            scanf("%d", &values[t]);
            ptr_values[t] = &values[t];
        	insert(list, index-2, ptr_values[t]);
            t++;
            count++;
        }

        if (menu == 4)
        {
        	printf("!!!\n");
        }

        if (menu == 5)
        {
            p = lst;
            for (int i = 0; i < count; i++)
            {
                addelem(lst,values[i]);
            }
            listprint(lst);
            printf("\n");
            sort(lst);
            listprint(lst);
            printf("\n");
                for(int i = 0; i < count; i++)
            {
                printf("count: %d\n", count);
                popBack(list);
            }
            for (int i = 1; i < count+1; i++)
            {
                p = p->next;
                pushBack(list,&p->field);
            }
            for (int i = 0; i < count; i++)
            {
                deletelem(lst);
            }


        }

        if (menu == 6)
        {
        	printf("\n");
        	printDblLinkedList(list, printInt);
        }


	} 
}























// void main(void)
// {

// 	DblLinkedList *list = createDblLinkedList();

//     int a, b, c, d, e, f, g, h;
     
//     a = 10;
//     b = 20;
//     c = 30;
//     d = 40;
//     e = 50;
//     f = 60;
//     g = 70;
//     h = 80;
//     // pushFront(list, &a);
//     // pushFront(list, &b);
//     // pushFront(list, &c);
//     pushBack(list, &d);
//     pushBack(list, &e);
//     // pushBack(list, &f);
//     // printDblLinkedList(list, printInt);
//     // printf("length %d\n", list->size);
//     // printf("nth 2 %d\n", *((int*)(getNthq(list, 2))->value));
//     // printf("nth 5 %d\n", *((int*)(getNthq(list, 5))->value));
//     // printf("popFront %d\n", *((int*)popFront(list)));
//     // printf("popFront %d\n", *((int*)popFront(list)));
//     // printf("head %d\n", *((int*)(list->head->value)));
//     // printf("tail %d\n", *((int*)(list->tail->value)));
//     // printf("popBack %d\n", *((int*)popBack(list)));
//     // printf("popBack %d\n", *((int*)popBack(list)));
//     // printf("length %d\n", list->size);
//     // printDblLinkedList(list, printInt);
//     insert(list, 0, &g);
//     // insert(list, 3, &h);
//     printDblLinkedList(list, printInt);
//     sort(list);
//     // deleteNth(list, 0);
//     printDblLinkedList(list, printInt);
//     // deleteDblLinkedList(&list);
// }