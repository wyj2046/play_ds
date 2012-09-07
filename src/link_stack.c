#include "link_stack.h"

bool push(LinkStack* stack, int element)
{
    StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
    new_node->data = element;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->count++;
    
    return true;
}

bool pop(LinkStack* stack, int* element)
{
    if (stack->count == 0)
    {
	return false;
    }
    
    *element = stack->top->data;
    StackNode* delete_node = stack->top;
    stack->top = stack->top->next;
    free(delete_node);
    stack->count--;

    return true;
}
