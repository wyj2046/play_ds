#ifndef _LINK_QUEUE_H_
#define _LINK_QUEUE_H_

typedef struct QueueNode
{
    int data;
    QueueNode* next;
}QueueNode;

typedef struct LinkQueue
{
    QueueNode* front;
    QueueNode* rear;
}LinkQueue;

bool enter_queue(LinkQueue* queue, int element);
bool dequeue(LinkQueue* queue, int* element);

#endif /* _LINK_QUEUE_H_ */
