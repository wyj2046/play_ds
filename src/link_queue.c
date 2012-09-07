#include "link_queue.h"

bool enter_queue(LinkQueue* queue, int element)
{
    QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
    new_node->data = element;
    new_node->next = NULL;
    queue->rear->next = new_node;
    queue->rear = new_node;

    return true;
}

bool dequeue(LinkQueue* queue, int* element)
{
    if (queue->front == queue->rear)
    {
	return false;
    }

    QueueNode* delete_node = queue->front->next;
    *element = delete_node->data;
    queue->front->next = delete_node->next;

    if (queue->rear = delete_node)
    {
	queue->rear = queue->front;
    }
    
    free(delete_node);

    return true;
}
