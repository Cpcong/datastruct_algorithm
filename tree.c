#include "tree.h"
#include "stdio.h"
#include "stdlib.h"

struct TreeNode{
    ElementType e;
    SearchTree l;
    SearchTree r;
};

SearchTree MakeEmpty(SearchTree t)
{
    if(t != NULL){
        MakeEmpty(t->l);
        MakeEmpty(t->r);
        free(t);
    }
    return NULL;
}

Position Find(ElementType e, SearchTree t)
{
    if(t != NULL){
        if(e < t->e){
            return Find(e, t->l); 
        }else if(e > t->e){
            return Find(e, t->r); 
        }else{
            return t; 
        } 
    }
    return NULL;
}

Position FindMin(SearchTree t)
{
    if(t == NULL){
        return NULL; 
    }
    if(t->l != NULL){
        return FindMin(t->l); 
    }
    return t;
}

Position FindMax(SearchTree t)
{
    if(t == NULL){
        return NULL; 
    }
    if(t->r != NULL){
        return FindMax(t->r); 
    }
    return t;
}

SearchTree Insert(ElementType e, SearchTree t)
{
    
    if(t == NULL){
        t = malloc(sizeof(struct TreeNode)); 
        if(t == NULL){
            printf("malloc t failed, out of space\n");
            exit(0);
        }
        t->e = e;
        t->l = NULL;
        t->r = NULL;
    }else if(e < t->e){
        t->l = Insert(e, t->l); 
    }else if(e > t->e){
        t->r = Insert(e, t->r);
    }
    return t;        
}

SearchTree Delete(ElementType e, SearchTree t)
{
    Position n; 
    if(t == NULL){
        printf("Delete failed\n");
        exit(0);
    }else if(e < t->e){
        t->l = Delete(e, t->l); 
    }else if(e > t->e){
        t->r = Delete(e, t->r); 
    }else if(t->r && t->l){
        n = FindMin(t->r);
        t->e = n->e;
        t->r = Delete(t->e, t->r);
    }else{
        n = t;
        if(t->r == NULL){
            t = t->l;
        }else if(t->l ==NULL){
            t = t->r;
        }
        free(n); 
    }
    return t;
}

ElementType Retrieve(Position p)
{
    if(p == NULL){
        printf("Retrieve failed, p is null\n");
        exit(0);
    } 
    return p->e;
}

int main()
{
    SearchTree t;
    t->l = t->r = NULL;
    Position p;

    Insert(1, t);
    Insert(5, t);
    Insert(7, t);
    Insert(2, t);
    p = Find(1, t);
    printf("p->e : %d\n", p->e);
    p = Find(2, t);
    printf("p->e : %d\n", p->e);
    p = FindMin(t);
    printf("min : %d\n", p->e);
    p = FindMax(t);
    printf("max : %d\n", p->e);
    Delete(7, t);
    p = FindMax(t);
    printf("max : %d\n", p->e);

    return 0; 
}
