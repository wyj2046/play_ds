#define MAXSIZE 20

typedef struct Sequence_list
{
    int data[MAXSIZE];
    int length;
}Sequence_list;

bool get_element(Sequence_list list, int index, int* element)
{
    if (list.length <= 0 || index < 1 || index > list.length)
    {
	return false;
    }

    *element = list.data[index-1];

    return true;
}

bool insert_element(Sequence_list* list, int index, int element)
{
    if (list->length == MAXSIZE || index < 1 || index > list->length)
    {
	return false;
    }

    if (index <= list->length)
    {
	for (int i = list->length - 1; i >= index-1; --i)
	{
	    list->data[i+1] = list->data[i];
	}
    }
    list->data[index-1] = element;
    list->length++;
    
    return true;
}

bool delete_element(Sequence_list* list, int index, int* element)
{
    if (list->length == 0 || index < 1 || index > list->length)
    {
	return false;
    }
    
    *element = list->data[index-1];

    if (index < list->length)
    {
	for (int i = index; i < list->length; ++i)
	{
	    list->data[i-1] = list->data[i];
	}
    }
    
    list->length--;

    return true;
}
