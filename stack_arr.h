#ifndef _STACK_ARR_H
#define _STACK_ARR_H

struct StackRecord;
typedef struct StackRecord *Stack;
typedef int ElementType;

int IsEmpty(Stack s);
int IsFull(Stack s);
Stack CreateStack(int MaxElements);
void MakeEmpty(Stack s);
void DisposeStack();
void Push(ElementType e, Stack s);
ElementType Top(Stack s);
void Pop(Stack s);
ElementType TopAndPop(Stack s);

#endif
