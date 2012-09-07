#ifndef _SEQUENCE_DOUBLE_STACK_H_
#define _SEQUENCE_DOUBLE_STACK_H_

#define MAXSIZE 20

typedef struct Sequence_double_stack
{
    int data[MAXSIZE];
    int top1;
    int top2;
}Sequence_double_stack;

bool push(Sequenc_double_stack* stack, int element, int stack_number);
bool pop(Sequenc_double_stack* stack, int* element, int stack_number);

#endif /* _SEQUENCE_DOUBLE_STACK_H_ */
