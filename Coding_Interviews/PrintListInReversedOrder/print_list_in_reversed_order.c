/*
题目：
输入一个链表的头结点，从尾到头反过来打印出每个结点的值
*/

/*
要求不改变链表结构
*/

#include "stdio.h"
#include "stack.h"
#include "stdlib.h"
#include "list.h"

void PrintListReversingly_Iteratively(struct ListNode *pListNode)
{
    Stack s;
    struct ListNode *pNode = pListNode;
    s = CreateStack();
    while(pNode != NULL){
        Push(pNode->value, s); 
        pNode = pNode->next;
    }
    while(!IsEmpty(s)){
        printf("%d ", TopAndPop(s));
    }
}

//递归本质上就是一个栈结构
void PrintListReversingly_Recursively(struct ListNode *pListNode)
{
    if(pListNode == NULL){
        return; 
    }
    PrintListReversingly_Recursively(pListNode->next);
    printf("%d ", pListNode->value);
}

//===================测试代码=================
void Test(struct ListNode *pListNode)
{
    PrintListReversingly_Iteratively(pListNode);
    printf("\n");
    PrintListReversingly_Recursively(pListNode);
}

// 1->2->3->4->5
void Test1()
{
    printf("\nTest1 begins.\n");

    struct ListNode *pListNode1 = CreateListNode(1);
    struct ListNode *pListNode2 = CreateListNode(2);
    struct ListNode *pListNode3 = CreateListNode(3);
    struct ListNode *pListNode4 = CreateListNode(4);
    struct ListNode *pListNode5 = CreateListNode(5);

    ConnectListNodes(pListNode1, pListNode2);
    ConnectListNodes(pListNode2, pListNode3);
    ConnectListNodes(pListNode3, pListNode4);
    ConnectListNodes(pListNode4, pListNode5);

    Test(pListNode1);
}

// 只有一个结点的链表: 1
void Test2()
{
    printf("\nTest2 begins.\n");

    struct ListNode* pNode1 = CreateListNode(1);

    Test(pNode1);

}

// 空链表
void Test3()
{
    printf("\nTest3 begins.\n");

    Test(NULL);
}

int main()
{
    Test1();
    Test2();
    Test3();

    return 0;
}








