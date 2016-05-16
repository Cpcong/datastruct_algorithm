#ifndef _HASH_OPEN_H
#define _HASH_OPEN_H

typedef char* ElementType;
typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int talbeSize);
void DestroyTable(HashTable H);
Position Find(ElementType e, HashTable h);
void Insert(ElementType e, HashTable h);
ElementType Retrieve(Position p, HashTable h);
HashTable ReHash(HashTable h);

#endif
