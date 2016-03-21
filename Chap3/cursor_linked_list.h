#ifndef _CURSOR_H
#define _CURSOR_H

typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;
void InitializeCursorSpace();

int MakeEmpty(List L);
int IsEmpty(const List L);
int IsLast(const Position p, const List L);
Position Find(ElementType e, const List L);
void Delete(ElementType e, List L);
Position FindPrevious(ElementType e, const List L);
void Insert(ElementType e, List L, Position p);
void DeleteList(List L);
Position Header(const List L);
Position First(const List L);
ElementType Retrieve(const Position p);

struct Node{
    ElementType e;
    Position next;
};
#define SPACE_SIZE 20

#endif
