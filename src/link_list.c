#include "link_list.h"

#include <stdlib.h>
#include <time.h>

bool get_element(Link_list list, int index, int* element)
{
    Node* p = list->next;
    int i = 1;
    while (p != NULL && i < index)
    {
	p = p->next;
	++i;
    }

    if (p == NULL || i > index)
    {
	return false;
    }

    *element = p->data;

    return true;
}

bool insert_element(Link_list* list, int index, int element)
{
    Node* p = *list;
    int i = 1;
    while (p != NULL && i < index)
    {
	p = p->next;
	++i;
    }

    if (p == NULL || i > index)
    {
	return false;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = element;
    new_node->next = p->next;
    p->next = new_node;

    return true;
}

bool delete_element(Link_list* list, int index, int* element)
{
    Node* p = *list;
    int i = 1;
    while (p->next != NULL && i < index)
    {
	p = p->next;
	++i;
    }

    if (p->next == NULL || i > index)
    {
	return false;
    }
    
    Node* delete_node = p->next;
    *element = delete_node->data;
    p->next = p->next->next;
    free(delete_node);
    
    return true;
}

void create_list_head(Link_list* list, int n)
{
    *list = (Link_list)malloc(sizeof(Node));
    (*list)->next = NULL;

    srand(time(0));
    Node* new_node = NULL;

    for (int i = 0; i < n; ++i)
    {
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = rand()%100 + 1;
	new_node->next = (*list)->next;
	(*list)->next = new_node;
    }
}

void create_list_tail(Link_list* &list, int n)
{
    *list = (Link_list)malloc(sizeof(Node));
    (*list)->next = NULL;

    Node* p = *list;

    srand(time(0));

    Node* new_node = NULL;
    for (int i = 0; i < n; ++i)
    {
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = rand()%100 + 1;
	p->next = new_node;
	p = new_node;
    }
    p->next = NULL;
}

/* Link_list array2list(int array[], int length) */
/* { */
/*     Link_list list = (Link_list)malloc(sizeof(Node)); */
/*     list->next = NULL; */

/*     Node* p = list; */

/*     Node* new_node = NULL; */
/*     for (int i = 0; i < length; ++i) */
/*     { */
/* 	new_node = (Node*)malloc(sizeof(Node)); */
/* 	new_node->data = array[i]; */
/* 	p->next = new_node; */
/* 	p = new_node; */
/*     } */
/*     p->next = NULL; */

/*     return list; */
/* } */
void  array2list(int array[], int length, Link_list* list)
{
    *list = (Link_list)malloc(sizeof(Node));
    (*list)->next = NULL;

    Node* p = *list;

    Node* new_node = NULL;
    for (int i = 0; i < length; ++i)
    {
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = array[i];
	p->next = new_node;
	p = new_node;
    }
    p->next = NULL;
}

void clear_list(Link_list* list)
{
    Node* p = (*list)->next;

    Node* temp_node = NULL;
    while (p != NULL)
    {
	temp_node = p->next;
	free(p);
	p = temp_node;
    }

    (*list)->next = NULL;
}
