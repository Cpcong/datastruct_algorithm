#ifndef _BINHEAP_h
#define _BINHEAP_h

struct HeapStruct;

typedef struct HeapStruct *PriorityQueue;
typedef int ElementType;

PriorityQueue Initialize(int maxElements);
void Destroy(PriorityQueue pq);
void MakeEmpty(PriorityQueue pq);
void Insert(ElementType e, PriorityQueue h);
ElementType DeleteMin(PriorityQueue h);
ElementType FindMin(PriorityQueue h);
int IsEmpty(PriorityQueue h);
int IsFull(PriorityQueue h);



#endif
