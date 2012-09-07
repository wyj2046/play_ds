#include "sequence_queue.h"

bool init_queue(SequenceQueue* queue)
{
    queue->front = 0;
    queue->rear = 0;

    retur ture;
}

int get_queue_length(SequenceQueue queue)
{
    return (queue->rear - queue->front + MAXSIZE) % MAXSIZE;
}

bool enter_queue(SequenceQueue* queue, int element)
{
    if ((queue->rear + 1) % MAXSIZE == queue->front)
    {
	return false;
    }

    queue->data[queue->rear] = element;
    queue->rear = (queue->rear + 1) % MAXSIZE;
    
    return true;
}

bool dequeue(SequenceQueue* queue, int* element)
{
    if (queue->front == queue->rear)
    {
	return false;
    }

    *element = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAXSIZE;

    return true;
}
