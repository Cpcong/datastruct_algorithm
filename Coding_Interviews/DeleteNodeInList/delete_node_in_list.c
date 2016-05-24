/*
题目：在O(1)时间删除链表结点
给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该结点.
*/
#include "list.h"
#include "stdlib.h"
#include "stdio.h"

//此处头结点就是链表第一个结点
void DeleteNode(struct ListNode **pListHead, struct ListNode *pToBeDeleted)
{

    struct ListNode *pLN;
    if(pListHead == NULL || pToBeDeleted == NULL){
        return ; 
    }
    //删除的结点不是尾结点
    if(pToBeDeleted->next != NULL){
        pLN = pToBeDeleted->next;
        pToBeDeleted->value = pLN->value;
        pToBeDeleted->next = pLN->next;
        free(pLN);
    }else if(pToBeDeleted == *pListHead){
        //链表只有一个结点，删除头结点(也是尾结点)
        free(pToBeDeleted); 
        *pListHead = NULL;
        pToBeDeleted = NULL;
    }else{
        //链表中有多个结点，删除尾结点
        pLN = *pListHead;
        while(pLN->next != pToBeDeleted){
            pLN = pLN->next; 
        }
        pLN->next = NULL;
        free(pToBeDeleted);
        pToBeDeleted = NULL;
    }
}

//================测试代码==================
void Test(struct ListNode *pListHead, struct ListNode * pNode)
{
    printf("The original list is:\n");    
    PrintList(pListHead);

    printf("The node to be deleted is:%d\n", pNode == NULL ? NULL : pNode->value);

    DeleteNode(&pListHead, pNode);
    printf("The result list is:\n");    
    PrintList(pListHead);
}

// 链表中有多个结点，删除中间的结点
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

    Test(pNode1, pNode3);

}

// 链表中有多个结点，删除尾结点
void Test2()
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

    Test(pNode1, pNode5);

}

// 链表中有多个结点，删除头结点
void Test3()
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

    Test(pNode1, pNode1);

}

// 链表中只有一个结点，删除头结点
void Test4()
{
    struct ListNode* pNode1 = CreateListNode(1);

    Test(pNode1, pNode1);
}

// 链表为空
void Test5()
{
    Test(NULL, NULL);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}








