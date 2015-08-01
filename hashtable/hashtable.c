#include <stdio.h>
#include <stdlib.h>

#include "hashtable.h"

HashTable *htCreate(int size)
{
    HashTable *ht;

    if (size < 1) {
        return NULL;
    }

    ht = (HashTable *) malloc(sizeof(HashTable));
    ht->size = size;
    ht->nodes = (HashTableNode *) malloc(sizeof(HashTableNode) * size);

    while (size--) {
        ht->nodes[size].nextNode = NULL;
        ht->nodes[size].keyLen = 0;
    }

    return ht;
}

void htFree(HashTable *ht)
{
    HashTableNode *node, *nextNode;
    int i, size;

    if (ht) {
        if (ht->nodes) {
            size = ht->size;
            for (i = 0; i < size; i++) {
                node = (ht->nodes + i)->nextNode;
                while (node) {
                    nextNode = node->nextNode;
                    free(node);
                    node = nextNode;
                }
            }
            free(ht->nodes);
        }
        free(ht);
    }
}

void *htGet(HashTable *ht, const char *key, int keyLen)
{
    HashTableNode *node;

    if (ht == NULL || keyLen < 1) {
        return NULL;
    }

    node = htNodeGet(ht, key, keyLen, hashOf(key, keyLen));
    if (node == NULL) {
        return NULL;
    }

    return node->value;
}

void htSet(HashTable *ht, const char *key, int keyLen, void *value)
{
    int index;
    HashTableNode *node;

    if (keyLen < 1) {
        return;
    }

    index = hashOf(key, keyLen);
    node = htNodeGet(ht, key, keyLen, index);

    if (node == NULL) {
        node = htNodeCreate(ht, index);
    }

    node->key = key;
    node->keyLen = keyLen;
    node->value = value;
}

void htOutput(HashTable *ht)
{
    HashTableNode *node, *node2;
    int i = 0;

    for (i = 0; i < ht->size; i++) {
        node = ht->nodes + i;
        if (node->keyLen < 1) {
            continue;
        }

        printf("--- %02d %s %s\n", i, node->key, (const char *) node->value);
        while (node = node->nextNode) {
            printf(" |-    %s %s\n", node->key, (const char *) node->value);
        }
    }
}

int hashOf(const char *key, int keyLen)
{
    const unsigned char *uchars;
    unsigned long h = 0, g;
    int i;

    uchars = (const unsigned char *) key;

    for (i = 0; i < keyLen; i++) {
        h = (h << 4) + (unsigned long) uchars[i];
        g = h & 0xF0000000UL;
        if (g != 0) {
            h ^= g >> 24;
        }
        h &= ~g;
    }

    return (int) h;
}

HashTableNode *htNodeGet(HashTable *ht, const char *key, int keyLen, int index)
{
    HashTableNode *node;

    for (node = ht->nodes + (index % ht->size); node != NULL; node = node->nextNode) {
        if (keyLen > 0 && keyLen == node->keyLen && strncmp(key, node->key, keyLen) == 0) {
            return node;
        }
    }

    return NULL;
}

HashTableNode *htNodeCreate(HashTable *ht, int index)
{
    HashTableNode *node, *node2;

    node = ht->nodes + (index % ht->size);
    if (node->keyLen < 1) {
        return node;
    }

    node2 = (HashTableNode *) malloc(sizeof(HashTableNode));
    node2->nextNode = node->nextNode;
    node->nextNode = node2;

    return node2;
}
