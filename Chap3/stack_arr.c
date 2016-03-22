#include "stdlib.h"
#include "stdio.h"
#include "stack_arr.h"

#define EMPTY -1

struct StackRecord{
    int capacity;
    int top;
    ElementType *arr;
};

int IsEmpty(Stack s)
{
    return s->top == EMPTY;
}

int IsFull(Stack s)
{
    return s->top == s->capacity;
}

Stack CreateStack(int MaxElements)
{
    Stack s;
    s = malloc(sizeof(struct StackRecord));
    if(s == NULL){
        printf("CreateStack malloc StackRecord error, out of space\n");
        exit(0);
    }
    s->capacity = MaxElements;
    s->arr = malloc(MaxElements * sizeof(ElementType));
    if(s->arr == NULL){
        printf("CreateStack malloc arr error, out of space\n");
        exit(0);
    }
    MakeEmpty(s);
    return s;
}

void MakeEmpty(Stack s)
{
    s->top = EMPTY;
}

void DisposeStack(Stack s)
{
    free(s->arr);
    free(s);
}

void Push(ElementType e, Stack s)
{
    if(IsFull(s)){
        printf("Push failed, Stack is Full\n");
        return;
    }
    s->top += 1;
    s->arr[s->top] = e;
}

ElementType Top(Stack s)
{
    if(IsEmpty(s)){
        printf("Top failed, Stack is empty\n");
        exit(0);
    }
    return s->arr[s->top];
}

void Pop(Stack s)
{
    if(IsEmpty(s)){
        printf("Pop failed, Stack is empty\n");
        exit(0);
    }
    s->top -= 1;
}

ElementType TopAndPop(Stack s)
{
    if(IsEmpty(s)){
        printf("TopAndPop failed, Stack is empty\n");
    }
    return s->arr[s->top--];
}

int main()
{
    ElementType e1 = 1;
    ElementType e2 = 2;
    Stack s = CreateStack(20);
    Push(e1, s);
    Push(e2, s);
    printf("Top: %d\n", Top(s));
    Pop(s);
    printf("Top: %d\n", Top(s));
    printf("TopAndPop: %d\n", TopAndPop(s));
    printf("isEmpty:%d\n", IsEmpty(s));
    DisposeStack(s);
    return 0;
}

