#include "stdio.h"
#include "stdlib.h"
#include "splay.h"

#define NEGINFINITY 0 
#define INFINITY  9999

struct SplayNode{
    ElementType e;
    SplayTree left;
    SplayTree right;
};

static Position NullNode = NULL;

SplayTree Initial()
{
    NullNode = (struct SplayNode*)malloc(sizeof(struct SplayNode)); 
    if(NullNode == NULL){
        printf("Initial failed, out of space\n"); 
        exit(0);
    }
    NullNode->left = NullNode->right = NullNode;
    return NullNode;
}

static SplayTree SingleRotateWithLeft(SplayTree k2)
{
    SplayTree k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    return k1;
}

static SplayTree SingleRotateWithRight(SplayTree k1)
{
    SplayTree k2;
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    return k2;
}

static SplayTree DoubleRotateWithLeft(SplayTree k3)
{
    k3->left = SingleRotateWithRight(k3->left);
    k3 = SingleRotateWithLeft(k3);
    return k3;
}

static SplayTree DoubleRotateWithRight(SplayTree k1)
{
    k1->right = SingleRotateWithLeft(k1->right);
    k1 = SingleRotateWithRight(k1);
    return k1;
}

SplayTree MakeEmpty(SplayTree t)
{
    if(t != NULL){
        MakeEmpty(t->right);
        MakeEmpty(t->left);
        free(t);
    }
    return NULL;
}


static SplayTree Splay(ElementType e, SplayTree t)
{

    static struct SplayNode Header;     
    Position LeftTreeMax, RightTreeMin;

    Header.left = Header.right = NullNode;
    //L树和R树对应存在header的右左子树
    LeftTreeMax = RightTreeMin = &Header; 
    //此处对NullNode->e的赋值有效的防止了NullNode被旋转上来
    NullNode->e = e;

    while(e != t->e){
        if(e < t->e){
            if(e < t->left->e){
                //一字型(/)
                t = SingleRotateWithLeft(t); 
            } 
            if(t->left == NullNode){
                break; 
            }
            //把提上来的根节点放在R树中
            RightTreeMin->left = t;
            RightTreeMin = t;
            t = t->left;
        }else{
            if(e > t->right->e){
                //一字型(\)
                t = SingleRotateWithRight(t); 
            } 
            if(t->right == NullNode){
                break; 
            }
            //把提上来的根节点放在L树中
            LeftTreeMax->right = t;
            LeftTreeMax = t;
            t = t->right;
        } 
    }
    //R树中所有节点都比t中所有节点大
    RightTreeMin->left = t->right;
    //L树中所有节点都比t中所有节点小
    LeftTreeMax->right = t->left; 
    //t->left = L树(这里容易混淆，header.right是L树)
    t->left = Header.right;
    t->right = Header.left;
    
    return t;
}

SplayTree Insert(ElementType e, SplayTree t)
{
    static Position NewNode = NULL;

    if(NewNode == NULL){
        NewNode = malloc(sizeof(struct SplayNode));    
        if(NewNode == NULL){
            printf("malloc NewNode failed, out of space\n"); 
            exit(0);
        }
    }
    NewNode->e = e;
    if(t == NullNode){
        NewNode->left = NewNode->right = NullNode;
        t = NewNode; 
    }else{
        //如果查找不到，则返回的t是最接近e的
        t = Splay(e, t); 
        if(e < t->e){
            //因为t最接近e，且e小于t->e，则e的大小位于t跟t->left之间 t->left->e < e< t->e
            NewNode->left = t->left;
            NewNode->right = t;
            t->left = NullNode;
            t = NewNode;
        
        }else if(e > t->e){
            //因为t最接近e，且e大于t->e，则e的大小位于t跟t->right之间 t-e < e < t->right->e
            NewNode->right = t->right;
            NewNode->left = t;
            t->right = NullNode;
            t = NewNode;
        }else{
            return t; 
        }
    }
    NewNode = NULL;
    return t;
}

SplayTree Find(ElementType e, SplayTree t)
{
    return  Splay(e, t);
}

SplayTree FindMin(SplayTree t)
{
    return Splay(NEGINFINITY, t);    
}

SplayTree FindMax(SplayTree t)
{
    return Splay(INFINITY, t);
}

SplayTree Remove(ElementType e, SplayTree t)
{
    Position newTree;
    if(t != NullNode){
     
        t = Splay(e, t);
        if(e == t->e){
            if(t->left == NullNode){
                newTree = t->right; 
            }else{
                newTree = t->left;
                //此时newTree中的结点全部小于e,Splay(e, newTree)返回的是最大的节点，此节点没有右子树
                newTree = Splay(e, newTree);
                newTree->right = t->right;
            } 
            free(t);
            t = newTree;
        }
    } 
    return t;
}

ElementType Retrieve(SplayTree t)
{
    return t->e;
}

//注意，不管是Insert, Find, FindMin..，返回的都是tree的根节点，要及时更新根节点的值，即每次将t传进去后将返回值赋给t，否则t将是不完整的
int main()
{
    SplayTree t = Initial();
    t = Insert(1, t);
    t = Insert(6, t);
    t = Insert(8, t);
    t = Insert(7, t);
    t = Find(3, t);
    printf("p->e:%d\n", t->e);
    t = FindMax(t);
    printf("max:%d\n", t->e);
    t = FindMin(t);
    printf("min:%d\n", t->e);
    t = Remove(8,t);
    printf("max:%d\n", t->e);
    return 0;
}
