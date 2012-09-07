#include "sequence_double_stack.h"

bool push(Sequenc_double_stack* stack, int element, int stack_number)
{
    if (stack->top1 + 1 == stack->top2)
    {
	return false;
    }

    if (stack_number == 1)
    {
	stack->data[++stack->top1] = element;
    }

    if (stack_number == 2)
    {
	stack->data[--stack->top2] = element;
    }

    return true;
}

bool pop(Sequenc_double_stack* stack, int* element, int stack_number)
{
    if (stack_number == 1)
    {
	if (stack->top1 == -1)
	{
	    return false;
	}
	*element = stack->data[stack->top1--];
    }

    if (stack_number == 2)
    {
	if (stack->top2 == MAXSIZE)
	{
	    return false;
	}
	*element = stack->data[stack->top2++];
    }

    return ture;
}
