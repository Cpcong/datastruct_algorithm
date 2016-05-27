/*
题目：链表中倒数第k个结点
输入一个链表，输出该链表中倒数第k个结点。
为了符合大多数人的习惯，本题从1开始计数，即链表的尾结点是倒数第一个结点。
例如一个链表有6个结点，从头结点开始它们的值依次是1, 2, 3, 4, 5, 6。
这个链表的倒数第3个结点是值为4的结点
*/

/*
解决思路：
利用两个指针(距离k-1个位置),两个指针同时走，当后面的指针到达尾结点时，
前面的指针指向的就是倒数第k个结点
注意点：
链表长度不够k大
输入参数不合法
*/
#include "list.h"
#include "stdlib.h"
#include "stdio.h"

struct ListNode* FindKthToTail(struct ListNode *pListHead, unsigned int k)
{
    struct ListNode* ln1; 
    struct ListNode* ln2; 
    int i;
    if(pListHead == NULL || k < 1){
        return NULL; 
    }
    ln1 = pListHead;
    ln2 = pListHead;
    for(i = 0;i < k - 1;i++){
        if(ln2->next == NULL){
            return NULL; 
        } 
        ln2 = ln2->next;
    }
    while(ln2->next != NULL){
        ln2 = ln2->next;
        ln1 = ln1->next;
    }
    return ln1;
}

// ====================测试代码====================
// 测试要找的结点在链表中间
void Test1()
{
    printf("=====Test1 starts:=====\n");
    struct ListNode* pNode1 = CreateListNode(1);
    struct ListNode* pNode2 = CreateListNode(2);
    struct ListNode* pNode3 = CreateListNode(3);
    struct ListNode* pNode4 = CreateListNode(4);
    struct ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 4.\n");
    struct ListNode* pNode = FindKthToTail(pNode1, 2);
    PrintListNode(pNode);


}

// 测试要找的结点是链表的尾结点
void Test2()
{
    printf("=====Test2 starts:=====\n");
    struct ListNode* pNode1 = CreateListNode(1);
    struct ListNode* pNode2 = CreateListNode(2);
    struct ListNode* pNode3 = CreateListNode(3);
    struct ListNode* pNode4 = CreateListNode(4);
    struct ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 5.\n");
    struct ListNode* pNode = FindKthToTail(pNode1, 1);
    PrintListNode(pNode);
}

// 测试要找的结点是链表的头结点
void Test3()
{
    printf("=====Test3 starts:=====\n");
    struct ListNode* pNode1 = CreateListNode(1);
    struct ListNode* pNode2 = CreateListNode(2);
    struct ListNode* pNode3 = CreateListNode(3);
    struct ListNode* pNode4 = CreateListNode(4);
    struct ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 1.\n");
    struct ListNode* pNode = FindKthToTail(pNode1, 5);
    PrintListNode(pNode);


}

// 测试空链表
void Test4()
{
    printf("=====Test4 starts:=====\n");
    printf("expected result: NULL.\n");
    struct ListNode* pNode = FindKthToTail(NULL, 100);
    PrintListNode(pNode);
}

// 测试输入的第二个参数大于链表的结点总数
void Test5()
{
    printf("=====Test5 starts:=====\n");
    struct ListNode* pNode1 = CreateListNode(1);
    struct ListNode* pNode2 = CreateListNode(2);
    struct ListNode* pNode3 = CreateListNode(3);
    struct ListNode* pNode4 = CreateListNode(4);
    struct ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: NULL.\n");
    struct ListNode* pNode = FindKthToTail(pNode1, 6);
    PrintListNode(pNode);

}

// 测试输入的第二个参数为0
void Test6()
{
    printf("=====Test6 starts:=====\n");
    struct ListNode* pNode1 = CreateListNode(1);
    struct ListNode* pNode2 = CreateListNode(2);
    struct ListNode* pNode3 = CreateListNode(3);
    struct ListNode* pNode4 = CreateListNode(4);
    struct ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: NULL.\n");
    struct ListNode* pNode = FindKthToTail(pNode1, 0);
    PrintListNode(pNode);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}

