#include "stdio.h"
#include "stdlib.h"
#include "hash_open.h"
#include "string.h"
#include "math.h"

enum KindOfEntry{
    Legitimate,
    Empty,
    Delete
};

struct HashEntry{
    char e[20];
    enum KindOfEntry info;
};

typedef struct HashEntry Cell;

struct HashTbl{
    int tableSize;
    Cell *theCells;
};

static int Hash(ElementType e, int tableSize)
{
    int hashVal = 0;
    while((*e) != '\0'){
        hashVal += hashVal << 5 + *e++;
    }
    return hashVal % tableSize; 
}
static int isPrime(int val)
{
    int i;
    for(i = 2;i <= sqrt(val);i++){
        if(val%i == 0){
            return 0;
        }
    }
    return 1;
}

static int NextPrime(int val)
{
    while(!isPrime(val)){
        val++;
    }
    return val;
}

HashTable InitializeTable(int tableSize)
{
    HashTable h;
    int i;
    h = malloc(sizeof(struct HashTbl));
    if(h == NULL){
        printf("InitializeTable failed, out of space\n"); 
        exit(0);
    }
    h->tableSize = NextPrime(tableSize);
    h->theCells = malloc(sizeof(struct HashEntry) * h->tableSize);
    if(h->theCells == NULL){
        printf("InitializeTable failed, out of space\n"); 
        exit(0);
    }
    for(i = 0;i < h->tableSize;i++){
        h->theCells[i].info = Empty; 
    }

    return h;
}

void DestroyTable(HashTable h)
{
    free(h->theCells);
    free(h);
}

Position Find(ElementType e, HashTable h)
{
    int cur = Hash(e, h);
    int cnt = 0;
    while(h->theCells[cur].info != Empty && (strcmp(h->theCells[cur].e, e)) != 0){
        cur = cur + 2 * (cnt + 1) - 1; 
        cnt++;
        //若元素过多,会导致cur增长太快，访问越界
        if(cur >= h->tableSize){
            cur = cur - h->tableSize; 
        }
    }
    return cur;
}

void Insert(ElementType e, HashTable h)
{
    Position p;
    p = Find(e, h); 
    if(h->theCells[p].info == Empty){
        h->theCells[p].info = Legitimate; 
        strcpy(h->theCells[p].e, e);
    }
}

ElementType Retrieve(Position p, HashTable h)
{
    return h->theCells[p].e;
}

HashTable ReHash(HashTable h)
{
    Cell *oldCells;
    int oldSize;
    int i;
    int hashVal;
    oldCells = h->theCells;
    oldSize = h->tableSize;
    //free(h);
    h = InitializeTable(2 * oldSize);
    for(i = 0;i < oldSize;i++){
        if(oldCells[i].info == Legitimate){
            Insert(oldCells[i].e, h);
        }
    }
    free(oldCells);
    return h;


}

int main()
{
    char *e = "hello";
    char *e2 = "world";
    Position p;
    HashTable h = InitializeTable(32);
    Insert(e, h);
    Insert(e2, h);
    p = Find(e2, h); 
    printf("%s\n", Retrieve(p, h));
    p = Find(e, h); 
    printf("%s\n", Retrieve(p, h));
    //DestroyTable(h);
    h = ReHash(h);
    
    p = Find(e2, h); 
    printf("%s\n", Retrieve(p, h));
    p = Find(e, h); 
    printf("%s\n", Retrieve(p, h));
    
    return 0;
}
