#include "stdio.h"
#include "binheap.h"
#include "stdlib.h"

#define MIN_DATA 0

struct HeapStruct{
    int capacity;
    int size;
    ElementType *elements;
};

PriorityQueue Initialize(int maxElements)
{
    PriorityQueue pq = malloc(sizeof(struct HeapStruct));
    if(pq == NULL){
        printf("Initialize failed, out of space\n"); 
        exit(0);
    }
    pq->elements = malloc(sizeof(ElementType) * maxElements);
    if(pq->elements == NULL)
    {
        printf("Initialize failed, out of space\n"); 
        exit(0);
    }
    pq->size = 0;
    pq->capacity = maxElements;
    pq->elements[0] = MIN_DATA;//作为边界
    return pq;
}

void Destroy(PriorityQueue pq)
{
    if(pq != NULL){
        free(pq->elements); 
        free(pq);
    }
}

void MakeEmpty(PriorityQueue pq)
{
    if(pq != NULL){
        pq->size = 0; 
    }
}

int IsFull(PriorityQueue pq)
{
    if(pq->size >= pq->capacity){
        return 1; 
    }else{
        return 0; 
    }
}

int IsEmpty(PriorityQueue pq)
{
    if(pq->size == 0){
        return 1; 
    }else{
        return 0; 
    }
}

void Insert(ElementType e, PriorityQueue pq)
{
    int i;
    if(IsFull(pq)){
        printf("Insert failed, queue is full\n"); 
        exit(0);
    } 
    pq->size += 1;
    for(i = pq->size;pq->elements[i/2] > e; i /= 2){
        pq->elements[i] = pq->elements[i/2]; 
    } 
    pq->elements[i] = e;
}

ElementType DeleteMin(PriorityQueue pq)
{
    int i, child;
    if(IsEmpty(pq)){
        printf("DeleteMin failed, PriorityQueue is Empty\n"); 
        exit(0);
    }
    int min = pq->elements[1];
    int lastElement = pq->elements[pq->size];
    pq->size -= 1;
    for(i = 1;i * 2< pq->size; i = child){
        child = i * 2;
        if(child != pq->size && (pq->elements[child] > pq->elements[child + 1])){
            child++;
        }
        if(lastElement > pq->elements[child]){
            pq->elements[i] = pq->elements[child]; 
        }else{
            break;
        }
    }
    pq->elements[i] = lastElement; 
    return min;
}

ElementType FindMin(PriorityQueue pq)
{
    return pq->elements[1];
}

int main()
{
    ElementType e1 = 1;
    ElementType e2 = 3;
    ElementType e3 = 7;
    PriorityQueue pq = Initialize(10);
    Insert(e2, pq);
    Insert(e3, pq);
    printf("min:%d\n", FindMin(pq));
    Insert(e1, pq);
    printf("delete min:%d\n", DeleteMin(pq));
    printf("min:%d\n", FindMin(pq));
    MakeEmpty(pq);
    Destroy(pq);
    return 0;
}
