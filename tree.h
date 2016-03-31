#ifndef _TREE_H
#define _TREE_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int ElementType;

SearchTree MakeEmpty(SearchTree t);
Position Find(ElementType e, SearchTree t);
Position FindMin(SearchTree t);
Position FindMax(SearchTree t);

SearchTree Insert(ElementType e, SearchTree t);
SearchTree Delete(ElementType e, SearchTree t);
ElementType Retrieve(Position p);

#endif
