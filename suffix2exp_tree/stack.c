#include "stack.h"
#include "stdio.h"
#include "stdlib.h"

struct Node{
    ElementType e;
    struct Node *next;
};

int IsEmpty(Stack s)
{
    return s->next == NULL;
}

Stack CreateStack()
{
    Stack s;
    s = malloc(sizeof(struct Node));
    s->next = NULL;
    return s;
}


void MakeEmpty(Stack s)
{
    if(s == NULL){
        printf("Must use CreateStack first\n");
        exit(0);
    }
    while(!IsEmpty(s)){
       Pop(s);
    }
}

void Push(ElementType e, Stack s)
{
    PtrToNode pNode;
    pNode = malloc(sizeof(struct Node));
    if(pNode == NULL){
         printf("out of space!!\n");
         exit(0);
    }
    pNode->e = e;
    pNode->next = s->next;
    s->next = pNode;
}

ElementType Top(Stack s)
{
    if(IsEmpty(s)){
        printf("Stack is empty, Top failed\n");
        return 0;
    }
    return s->next->e;
}

void Pop(Stack s){
    PtrToNode pNode;
    if(IsEmpty(s)){
         printf("Stack is empty, Pop failed\n");
        return;
    }
    pNode = s->next;
    s->next = pNode->next;
    free(pNode);
}

ElementType TopAndPop(Stack s)
{
    ElementType e;
    if(IsEmpty(s)){
        printf("TopAndPop failed, Stack is empty\n");
        exit(0);
    }
    e = Top(s);
    Pop(s);
    return e;

}


/*
int main()
{
    Stack s;
    ElementType e1 = 1;
    ElementType e2 = 2;
    s = CreateStack();
    printf("IsEmpty: %s\n", IsEmpty(s) ? "true" : "false");

    Push(e1, s);
    Push(e2, s);

    printf("Top: %d\n", Top(s));
    Pop(s);
    printf("Top: %d\n", Top(s));


    return 0;
}
*/
