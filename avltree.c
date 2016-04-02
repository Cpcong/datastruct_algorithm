#include "stdio.h"
#include "stdlib.h"
#include "avltree.h"

struct AvlNode{
    ElementType e;
    AvlTree left;
    AvlTree right;
    int height;
};

static int Max(int n1, int n2)
{
    return n1 > n2 ? n1 : n2;
}

static int Height(Position p)
{
    if(p == NULL){
        return -1; 
    }else{
        return p->height; 
    }
}

static Position SingleRotateWithLeft(Position k2)
{
    Position k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = Max(Height(k2->left), Height(k2->right)) + 1;
    k1->height = Max(Height(k1->left), k2->height) + 1;

    return k1;
}

static Position SingleRotateWithRight(Position k1)
{
    Position k2;
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    
    k1->height = Max(Height(k1->left), Height(k1->right)) + 1;
    k2->height = Max(Height(k2->right), k1->height) + 1;
    return k2;
}

static Position DoubleRotateWithLeft(Position k3) 
{
    k3->left = SingleRotateWithRight(k3->left);
    return SingleRotateWithLeft(k3);
}

static Position DoubleRotateWithRight(Position k3)
{
    k3->right = SingleRotateWithLeft(k3->right);
    return SingleRotateWithRight(k3);
}

AvlTree Insert(ElementType e, AvlTree t)
{
    if(t == NULL){
        t = malloc(sizeof(struct AvlNode)); 
        t->e = e;
        t->height = 0;
        t->left = NULL;
        t->right = NULL;
    }
    if(e < t->e){
        t->left = Insert(e, t->left); 
        if(Height(t->left) - Height(t->right) == 2){
            if(e < t->left->e){
                t = SingleRotateWithLeft(t); 
            }else{
                t = DoubleRotateWithLeft(t); 
            }
        }
    }else if(e > t->e){
        t->right = Insert(e, t->right); 
        if(Height(t->right) - Height(t->left) == 2){
            if(e > t->right->e){
                t = SingleRotateWithRight(t); 
            }else{
                t = DoubleRotateWithRight(t); 
            } 
        }
    }
    t->height = Max(Height(t->left), Height(t->right)) + 1;
    return t;
}

AvlTree MakeEmpty(AvlTree t)
{
   if(t != NULL){
        MakeEmpty(t->left); 
        MakeEmpty(t->right);
        free(t);
   }
   return NULL;
}

Position Find(ElementType e, AvlTree t)
{
    if(t == NULL){
        return NULL; 
    }
    if(e < t->e){
        return Find(e, t->left); 
    }else if(e > t->e){
        return Find(e, t->right); 
    }else{
        return t; 
    } 
}

Position FindMin(AvlTree t)
{
    if(t == NULL){
        return NULL; 
    }
    if(t->left != NULL){
        return FindMin(t->left); 
    }else{
        return t; 
    }
}

Position FindMax(AvlTree t)
{
    if(t == NULL){
        return NULL; 
    }
    if(t->right != NULL){
        return FindMax(t->right); 
    }else{
        return t; 
    }
}
int main()
{
    AvlTree t = NULL; 
    Position p;
    t = Insert(1, t);
    t = Insert(2, t);
    t = Insert(5, t);
    p = Find(1, t);
    printf("p->e:%d\n", p->e);
    p = FindMin(t); 
    printf("Min:%d\n", p->e);
    p = FindMax(t);
    printf("Max:%d\n", p->e);
    return 0;
}
