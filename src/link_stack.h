#ifndef _LINK_STACK_H_
#define _LINK_STACK_H_

typedef struct StackNode
{
    int data;
    StackNode* next;
}StackNode;

typedef struct LinkStack
{
    StackNode* top;
    int count;
}LinkStack;

bool push(LinkStack* stack, int element);
bool pop(LinkStack* stack, int* element);

#endif /* _LINK_STACK_H_ */
