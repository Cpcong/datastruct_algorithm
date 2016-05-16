#ifndef _AVLTREE_H
#define _AVLTREE_H

struct AvlNode;
typedef struct AvlNode *AvlTree; 
typedef struct AvlNode *Position;
typedef int ElementType;

AvlTree MakeEmpty(AvlTree t);
Position Find(ElementType e, AvlTree t);
Position FindMin(AvlTree t);
Position FindMax(AvlTree t);
AvlTree Insert(ElementType e, AvlTree t);
AvlTree Delete(ElementType e, AvlTree t);
ElementType Retrieve(Position p);


#endif
