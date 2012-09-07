#ifndef _SEQUENCE_STACK_H_
#define _SEQUENCE_STACK_H_

#define MAXSIZE 20

typedef struct Sequence_stack
{
    int data[MAXSIZE];
    int top;
}Sequence_stack;

bool push(Sequence_stack* stack, int element);
bool pop(Sequence_stack* stack, int* element);

#endif /* _SEQUENCE_STACK_H_ */
