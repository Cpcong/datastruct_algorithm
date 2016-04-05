#ifndef _SPLAY_H
#define _SPLAY_H

struct SplayNode;

typedef struct SplayNode *SplayTree;
typedef struct SplayNode *Position;
typedef int ElementType;

SplayTree MakeEmpty(SplayTree t);
SplayTree Find(ElementType e, SplayTree t);
SplayTree FindMin(SplayTree t);
SplayTree FindMax(SplayTree t);
SplayTree Initial(void);
SplayTree Remove(ElementType e, SplayTree t);
SplayTree Insert(ElementType e, SplayTree t);
ElementType Retrieve(SplayTree t);

#endif
