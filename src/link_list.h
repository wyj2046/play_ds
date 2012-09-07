#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

typedef struct Node
{
    int data;
    Node* next;
}Node;

typedef Node* Link_list;

bool get_element(Link_list list, int index, int* element);

bool insert_element(Link_list* list, int index, int element);

bool delete_element(Link_list* list, int index, int* element);

void create_list_head(Link_list* list, int n);

void create_list_tail(Link_list* list, int n);

void  array2list(int array[], int length, Link_list* list);
// Link_list array2list(int array[], int length);

void clear_list(Link_list* list);


#endif /* _LINK_LIST_H_ */
