#include "list.h"
#include "stdlib.h"
#include "stdio.h"


struct ListNode* CreateListNode(int value)
{
    struct ListNode *pNode = malloc(sizeof(struct ListNode));
    pNode->value = value;
    pNode->next = NULL;
    return pNode;
}

void ConnectListNodes(struct ListNode *pCurrent, struct ListNode *pNext)
{
    if(pCurrent == NULL)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }
    pCurrent->next = pNext;
}

