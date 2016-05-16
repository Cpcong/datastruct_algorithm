#ifndef _HASH_SEQ_H
#define _HASH_SEQ_H

typedef char *ElementType;

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int tableSize);
void DestroyTable(HashTable h);
Position Find(ElementType e, HashTable h);
void Insert(ElementType e, HashTable h);
ElementType Retrieve(Position p);


#endif
