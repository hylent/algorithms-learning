#ifndef _HASHTABLE_H
#define _HASHTABLE_H

typedef struct _HashTableNode {
    struct _HashTableNode *nextNode;
    const char *key;
    int keyLen;
    void *value;
} HashTableNode;

typedef struct {
    int size;
    HashTableNode *nodes;
} HashTable;

HashTable *htCreate(int size);
void htFree(HashTable *ht);
void *htGet(HashTable *ht, const char *key, int keyLen);
void htSet(HashTable *ht, const char *key, int keyLen, void *value);
void htOutput(HashTable *ht);

int hashOf(const char *key, int keyLen);
HashTableNode *htNodeGet(HashTable *ht, const char *key, int keyLen, int index);
HashTableNode *htNodeCreate(HashTable *ht, int index);

#endif // _HASHTABLE_H
