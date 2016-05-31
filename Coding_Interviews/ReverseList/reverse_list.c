/*
题目：反转链表
定义一个函数，输入一个链表的头结点，反转该链表并输出反转后
链表的头结点
*/
#include "stdio.h"
#include "stdlib.h"
#include "list.h"

struct ListNode* ReverseList(struct ListNode* pHead)
{
    struct ListNode* pNode = pHead;
    struct ListNode* pNext;
    struct ListNode* pPre = NULL;
    struct ListNode* pReversedHead = NULL;
    while(pNode != NULL){
        pNext = pNode->next; 
        if(pNext == NULL){
            pReversedHead = pNode; 
        }      
        pNode->next = pPre;
        pPre = pNode;
        pNode = pNext;
    }
    return pReversedHead;
}

//递归法
struct ListNode* ReverseListRecursively(struct ListNode* pHead)
{
    if(pHead == NULL || pHead->next == NULL){
        return pHead; 
    }
    struct ListNode *newHead = ReverseListRecursively(pHead->next); 
    pHead->next->next = pHead;
    pHead->next = NULL;
    return newHead;
}

//=============测试代码============
struct ListNode* Test(struct ListNode* pHead)
{
    printf("The original list is:\n");
    PrintList(pHead);
    struct ListNode* pReversedHead = ReverseList(pHead);
    printf("The reversed list is: \n");
    PrintList(pReversedHead);
    struct ListNode *pReversedHead = ReverseListRecursively(pHead);
    printf("The reversed list(Recursive) is: \n");
    PrintList(pReversedHead);
    return pReversedHead; 
}

//输入的链表有多个结点
void Test1()
{
    struct ListNode* pNode1 = CreateListNode(1);
    struct ListNode* pNode2 = CreateListNode(2);
    struct ListNode* pNode3 = CreateListNode(3);
    struct ListNode* pNode4 = CreateListNode(4);
    struct ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    Test(pNode1);

}

//输入的链表只有一个结点
void Test2()
{
    struct ListNode* pNode1 = CreateListNode(1);
    Test(pNode1);
}

//输入空链表
void Test3()
{
    Test(NULL);
}
int main()
{
    Test1();
    Test2();
    Test3();
    return 0;
}
