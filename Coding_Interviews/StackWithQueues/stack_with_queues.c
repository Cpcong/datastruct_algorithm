/*
用两个队列实现一个栈
*/
#include "stdio.h"
#include "stdlib.h"
#include "queue_arr.h"

struct StackWithQueues{
    Queue q1;
    Queue q2;
};

typedef struct StackWithQueues *Stack;

Stack CreateStack(int size)
{
    Stack s = malloc(sizeof(struct StackWithQueues)); 
    if(s == NULL){
        printf("malloc failed, out of space.\n"); 
        exit(0);
    }
    s->q1 = CreateQueue(size);
    s->q2 = CreateQueue(size);
    return s;
}

void Push(int val, Stack s)
{
    //哪个队列非空就往哪个队列入队
    if(!IsEmpty(s->q2)){
        Enqueue(val, s->q2); 
    }else{
        Enqueue(val, s->q1); 
    }
}

int Pop(Stack s)
{
    //哪个队列非空就从哪个队列出队
    if(!IsEmpty(s->q1)){
        while(Size(s->q1) > 1){
            Enqueue(FrontAndDequeue(s->q1), s->q2); 
        } 
        return FrontAndDequeue(s->q1); 
    }else if(!IsEmpty(s->q2)){
        while(Size(s->q2) > 1){
            Enqueue(FrontAndDequeue(s->q2), s->q1); 
        } 
        return FrontAndDequeue(s->q2); 
    }else{
        printf("Pop failed, Stack is empty.\n"); 
        exit(0);
    }
    
}

//================测试代码=====================
void Test(char actual, char expected)
{
    if(actual == expected)
    {
        printf("Test passed.\n"); 
    }else{
        printf("Test failed.\n"); 
    }
}
int main()
{
    Stack s = CreateStack(20);

    Push('a', s);
    Push('b', s);
    Push('c', s);
    char tmp = Pop(s);
    Test('c', tmp);

    tmp = Pop(s);
    Test('b', tmp);

    Push('d', s);
    tmp = Pop(s);
    Test('d', tmp);
}
