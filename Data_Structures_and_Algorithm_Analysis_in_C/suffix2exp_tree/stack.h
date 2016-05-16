#ifndef _STACK_H
#define _STACK_H

typedef struct TreeNode *ElementType;

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;


int IsEmpty(Stack s);
Stack CreateStack();
void MakeEmpty(Stack s);
void Push(ElementType x, Stack s);
ElementType Top(Stack s);
void Pop(Stack s);
ElementType TopAndPop(Stack s);
#endif
