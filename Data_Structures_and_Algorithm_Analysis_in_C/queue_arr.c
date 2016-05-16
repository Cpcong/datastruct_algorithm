#include "stdio.h"
#include "stdlib.h"
#include "queue_arr.h"


struct QueueRecord{
    int capacity;
    int size;
    int front;
    int rear;
    ElementType *arr;
};

int IsEmpty(Queue q)
{
    return q->size == 0;
}

int IsFull(Queue q)
{
    return q->size == q->capacity;
}

void MakeEmpty(Queue q)
{
    q->size = 0;
    q->front = 1;
    q->rear = 0;
}
Queue CreateQueue(int capacity)
{
    Queue q;
    q = malloc(sizeof(Queue));
    if(q == NULL){
        printf("malloc q failed, out of space\n");
        exit(0);
    } 
    q->arr = malloc(sizeof(ElementType) * capacity);
    if(q->arr == NULL){
        printf("malloc q->arr failed, out of space\n");
        exit(0);
    }
    q->capacity = capacity;
    MakeEmpty(q);
    return q;
}

void DisposeQueue(Queue q)
{
    free(q->arr); 
    free(q); 
}

void Enqueue(ElementType e, Queue q)
{
    if(IsFull(q)){
        printf("Enqueue failed, q is full\n");
        exit(0); 
    } 
    if(++q->rear == q->capacity){
        q->rear = 0;
    } 
    q->arr[q->rear] = e;
    q->size++;
}

ElementType Front(Queue q)
{
    if(IsEmpty(q)){
        printf("Front failed, q is empty\n");
        exit(0);
    }
    return q->arr[q->front];
}

void Dequeue(Queue q)
{
    if(IsEmpty(q)){
        printf("Dequeue failed, q is empty\n");
        exit(0);
    }
    if(++q->front == q->capacity){
        q->front = 0;
    }
    q->size--;
}

ElementType FrontAndDequeue(Queue q)
{
    ElementType e = Front(q);
    Dequeue(q); 
    return e;
}



int main()
{
    Queue q = CreateQueue(5); 
    ElementType e1 = 1;
    ElementType e2 = 2;
    ElementType e3 = 3;
    ElementType e4 = 4;

    Enqueue(e1, q);
    Enqueue(e2, q);
    Enqueue(e3, q);
    Enqueue(e4, q);

    Dequeue(q);
    Dequeue(q);
    Dequeue(q);
    Dequeue(q);

    Enqueue(e1, q);
    Enqueue(e2, q);
    Enqueue(e3, q);
    Enqueue(e4, q);
    printf("FrontAndDequeue:%d\n", FrontAndDequeue(q));
    //printf("FrontAndDequeue:%d\n", FrontAndDequeue(q));
    Dequeue(q); 

    MakeEmpty(q);

    DisposeQueue(q);
    return 0;
}
