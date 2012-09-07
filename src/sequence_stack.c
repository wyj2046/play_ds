#include "sequence_stack.h"

bool push(Sequence_stack* stack, int element)
{
    if (stack->top == MAXSIZE - 1)
    {
	return false;
    }

    stack->top++;
    stack->data[stack->top] = element;

    return true;
}

bool pop(Sequence_stack* stack, int* element)
{
    if (stack->top == -1)
    {
	return false;
    }

    *element = stack->data[stack->top];
    stack->top--;

    return true;
}
