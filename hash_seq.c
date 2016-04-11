#include "stdio.h"
#include "stdlib.h"
#include "hash_seq.h"
#include "math.h"

struct ListNode{
    ElementType e;
    Position next;
};

typedef Position List;

struct HashTbl{
    int tableSize;
    List *lists;
};

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

static int Hash(char* key, int tableSize){
    unsigned int hashVal = 0;
    while((*key) != '\0'){
        hashVal = hashVal << 5 + *key++; 
    }
    return tableSize % tableSize;
}

HashTable InitializeTable(int tableSize)
{
    int i;
    HashTable hashTable = malloc(sizeof(struct HashTbl));
    if(hashTable == NULL){
        printf("InitializeTable failed, out of space\n"); 
        exit(0);
    }
    hashTable->tableSize = NextPrime(tableSize);
    hashTable->lists = malloc(hashTable->tableSize * sizeof(List));
    if(hashTable->lists == NULL){
        printf("InitializeTable failed, out of space\n"); 
        exit(0);
    }
    for(i = 0;i < hashTable->tableSize;i++){
        hashTable->lists[i] = malloc(sizeof(struct ListNode)); 
        hashTable->lists[i]->next = NULL;
    }
    return hashTable;
}

void Destroy(HashTable h)
{
    int i;
    Position p, t;
    for(i = 0;i < h->tableSize;i++){
        p = h->lists[i];
        while((t = p->next) != NULL){
            free(p); 
            p = t;
        }
        free(p);
    }
    free(h);
}

Position Find(ElementType e, HashTable h)
{
    Position p;
    int hashVal = Hash(e, h->tableSize); 
    p = h->lists[hashVal];
    while(p->next != NULL){
        if(p->next->e == e){
            return p->next; 
        }
        p = p->next;    
    }
    return NULL;

}

void Insert(ElementType e, HashTable h)
{
    Position header;
    Position p; 
    if((p = Find(e, h)) != NULL){
        ;//此处或许可以将节点提前
    }else{
        p = malloc(sizeof(struct ListNode));
        if(p == NULL){
            printf("malloc in Insert failed, out of space\n"); 
            exit(0);
        }
        header = h->lists[Hash(e, h->tableSize)];
        p->e = e;
        p->next = header->next;
        header->next = p;
    } 
}

ElementType Retrieve(Position p)
{
    return p->e;
}

int main()
{
    Position p;
    HashTable h = InitializeTable(33);
    Insert("he", h);
    Insert("ha", h);
    Insert("sha", h);
    Insert("haha", h);
    p = Find("ha", h);
    printf("%s\n", Retrieve(p));
    p = Find("sha", h);
    printf("%s\n", Retrieve(p));
    Destroy(h);    

    return 0;
}
