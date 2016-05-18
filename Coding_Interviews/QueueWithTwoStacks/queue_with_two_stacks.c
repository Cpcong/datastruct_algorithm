/*
题目：用两个栈实现队列
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail和deleteHead
分别在队列尾部插入结点和在队列头部删除结点的功能。

*/
#include "stdio.h"
#include "stack.h"
#include "stdlib.h"

struct Queue{
    Stack stack1;
    Stack stack2;
};

typedef struct Queue *pQueue;

pQueue CreateQueue()
{
    pQueue pq = malloc(sizeof(struct Queue)); 
    if(pq == NULL){
        printf("malloc failed, out of space.\n"); 
        exit(0);
    }
    pq->stack1 = CreateStack();
    pq->stack2 = CreateStack();
    return pq;
}

void AppendTail(pQueue pq, int value)
{
    Push(value, pq->stack1); 
}

int DeleteHead(pQueue pq)
{
    int result;
    if(IsEmpty(pq->stack2)){
        while(!IsEmpty(pq->stack1)){
            Push(TopAndPop(pq->stack1), pq->stack2); 
        }  
    }
    if(IsEmpty(pq->stack2)){
        printf("deleteHead failed, queue is empty.\n"); 
        exit(0);
    }
    result = TopAndPop(pq->stack2);
    return result;
}

//================测试代码==================
void Test(char actual, char expected)
{
    if(actual == expected){
        printf("Test passed.\n"); 
    }else{
        printf("Test failed.\n"); 
    }
}

int main()
{
    pQueue pq = CreateQueue();
    AppendTail(pq, 'a');
    AppendTail(pq, 'b');
    AppendTail(pq, 'c');

    char head = DeleteHead(pq); 
    Test(head, 'a');

    head = DeleteHead(pq); 
    Test(head, 'b');

    AppendTail(pq, 'd');
    head = DeleteHead(pq); 
    Test(head, 'c');

    AppendTail(pq, 'e');
    head = DeleteHead(pq); 
    Test(head, 'd');
    
    head = DeleteHead(pq); 
    Test(head, 'e');

    return 0;
}
