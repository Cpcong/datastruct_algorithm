#ifndef _LIST_H
#define _LIST_H

struct ListNode{
    int value;
    struct ListNode *next;
};


struct ListNode* CreateListNode(int value);
void ConnectListNodes(struct ListNode *pCurrent, struct ListNode *pNext);



#endif

