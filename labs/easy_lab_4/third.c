#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
 struct list
{
  int field; // поле данных
  struct list *next; // указатель на следующий элемент
  struct list *prev; // указатель на предыдущий элемент
};


struct list* getNth(struct list *lst, size_t index) {
    struct list *tmp = lst;
    size_t i = 0;
 
    while (tmp && i < index) {
        tmp = tmp->next;
        i++;
    }
 
    return tmp;
}

void insert(struct list *lst, size_t index, void *value) {
    struct  *elm = NULL;
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

struct list * init(int a)  // а- значение первого узла
{
  struct list *lst;
  // выделение памяти под корень списка
  lst = (struct list*)malloc(sizeof(struct list));
  lst->field = a;
  lst->next = NULL; // указатель на следующий узел
  lst->prev = NULL; // указатель на предыдущий узел
  return(lst);
}

struct list * addelem(struct list *lst, int number)
{
  struct list *temp, *p;
  temp = (struct list*)malloc(sizeof(struct list));
  p = lst->next; // сохранение указателя на следующий узел
  lst->next = temp; // предыдущий узел указывает на создаваемый
  temp->field = number; // сохранение поля данных добавляемого узла
  temp->next = p; // созданный узел указывает на следующий узел
  temp->prev = lst; // созданный узел указывает на предыдущий узел
  if (p != NULL)
    p->prev = temp;
  return(temp);
}






struct list * deletelem(struct list *lst)
{
  struct list *prev, *next;
  prev = lst->prev; // узел, предшествующий lst
  next = lst->next; // узел, следующий за lst
  if (prev != NULL)
    prev->next = lst->next; // переставляем указатель
  if (next != NULL)
    next->prev = lst->prev; // переставляем указатель
  free(lst); // освобождаем память удаляемого элемента
  return(prev);
}


void listprint(struct list *lst)
{
  struct list *p;
  p = lst;
  do {
    printf("%d ", p->field); // вывод значения элемента p
    p = p->next; // переход к следующему узлу
  } while (p != NULL); // условие окончания обхода
}

void main(void)
{
	int a; 
	struct list *lst;
	printf("Введите певрое значение: \n");
	scanf("%d",&a);
	lst = init(a);

	for (int i = 0; i < 3; i++)
	{
		addelem(lst, i);
	}
	listprint(lst);
}