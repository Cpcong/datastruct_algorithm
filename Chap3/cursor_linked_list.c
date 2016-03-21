#include "stdio.h"
#include "cursor_linked_list.h"

//freelist从索引0开始
//索引1的位置为链表的header
struct Node CursorSpace[SPACE_SIZE];

void InitializeCursorSpace()
{
    int i;
    for(i = 0;i < SPACE_SIZE - 1;i++){
        CursorSpace[i].next = i + 1;
    }
    CursorSpace[i].next = 0;
}

static Position CursorAlloc()
{
    Position t;
    t = CursorSpace[0].next;
    CursorSpace[0].next = CursorSpace[t].next;
    return t;
}

static void CursorFree(Position p)
{
    CursorSpace[p].next = CursorSpace[0].next;
    CursorSpace[0].next = p;
}

int MakeEmpty(List L)
{
    Position p, p2;
    p2 = p = CursorSpace[L].next;
    while(p){
        p2 = CursorSpace[p].next;
        CursorFree(p);
        p = p2;
    }
}

int IsEmpty(List L)
{
    return CursorSpace[L].next == 0;
}

int IsLast(Position p, List L)
{
    return CursorSpace[p].next == 0;
}

Position Find(ElementType e, List L)
{
    Position p;

    p = CursorSpace[L].next;
    while( p && CursorSpace[p].e != e){
        p = CursorSpace[p].next;
    }
    return p;
}

void Delete(ElementType e, List L)
{
     Position p, tmpCell;

     p = FindPrevious(e, L);
     if(!IsLast(p, L)){
        tmpCell = CursorSpace[p].next;
        CursorSpace[p].next = CursorSpace[tmpCell].next;
        CursorFree(tmpCell);
     }
}

void Insert(ElementType e, List L, Position p)
{
    Position p1;
    p1 = CursorAlloc();
    CursorSpace[p1].e = e;
    CursorSpace[p1].next = CursorSpace[p].next;
    CursorSpace[p].next = p1;
}

Position FindPrevious(ElementType e, const List L)
{
    Position preP = L;
    Position p = CursorSpace[L].next;
    while(p){
        if(CursorSpace[p].e == e){
            break;
        }
        preP = p;
        p = CursorSpace[p].next;
    }
    return preP;
}
//返回链表的第一个元素
Position First(const List L)
{
    return CursorSpace[L].next;
}
//返回链表的header
Position Header(const List L)
{
    return L;
}

List CursorList()
{
    List l = CursorAlloc();
    CursorSpace[l].next = 0;
    return l;
}

ElementType Retrieve(const Position p)
{
    return CursorSpace[p].e;
}

static void Iterate(List L)
{
    Position p;
    p = CursorSpace[L].next;

    while(p){
         printf("%d ", CursorSpace[p].e);
         p = CursorSpace[p].next;
    }
    printf("\n");
}

static void IterateFreeList()
{
    Position p;
    p = CursorSpace[0].next;
    while(p){
        printf("%d ", p);
        p = CursorSpace[p].next;
    }
    printf("\n");
}
int main()
{
    int i;
    InitializeCursorSpace();
    List l = CursorList();

    printf("List header: %d\n", Header(l));
    printf("insert 11, 12, 13 to Position 1, 2, 3\n");
    Insert(11, l, 1);
    Insert(12, l, 2);
    Insert(13, l, 3);
    printf("List First: %d\n", First(l));

    printf("value 12 in Position:%d\n", Find(12, l));
    printf("Iterate List : ");
    Iterate(l);
    Delete(11, l);
    printf("after delete value 11\n");
    printf("Iterate List : ");
    Iterate(l);

    printf("Iterate Free list: ");
    IterateFreeList();

    printf("Make empty\n");
    MakeEmpty(l);
    printf("Iterate List: ");
    Iterate(l);

    return 0;
}

