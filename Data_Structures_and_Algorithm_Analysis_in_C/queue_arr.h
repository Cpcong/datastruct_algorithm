#ifndef _QUEUE_STACK_H
#define _QUEUE_STACK_H

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef int ElementType;
int IsEmpty(Queue q);
int IsFull(Queue q);
Queue CreateQueue(int capacity);
void DisposeQueue(Queue q);
void MakeEmpty(Queue q);
void Enqueue(ElementType e, Queue q);
ElementType Front(Queue q);
void Dequeue(Queue q);
ElementType FrontAndDequeue(Queue q);

#endif
