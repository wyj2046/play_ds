#ifndef _SEQUENCE_QUEUE_H_
#define _SEQUENCE_QUEUE_H_

#define MAXSIZE 20

typedef struct SequenceQueue
{
    int data[MAXSIZE];
    int front;
    int rear;
}SequenceQueue;

bool init_queue(SequenceQueue* queue);
int get_queue_length(SequenceQueue queue);
bool enter_queue(SequenceQueue* queue, int element);
bool dequeue(SequenceQueue* queue, int* element);
#endif /* _SEQUENCE_QUEUE_H_ */
