#include <stdio.h>
#include <string.h>

#include "hashtable.h"

int main(void)
{
    HashTable *ht;
    void *value;

    ht = htCreate(16);
    if (!ht) {
        printf("Cannot create ht!\n");
        return 1;
    }

    htSet(ht, "@01", strlen("@01"), (void *) "DAT01");
    htSet(ht, "@02", strlen("@02"), (void *) "DAT02");
    htSet(ht, "@03", strlen("@03"), (void *) "DAT03");
    htSet(ht, "@04", strlen("@04"), (void *) "DAT04");
    htSet(ht, "@05", strlen("@05"), (void *) "DAT05");
    htSet(ht, "@06", strlen("@06"), (void *) "DAT06");
    htSet(ht, "@07", strlen("@07"), (void *) "DAT07");
    htSet(ht, "@08", strlen("@08"), (void *) "DAT08");
    htSet(ht, "@09", strlen("@09"), (void *) "DAT09");
    htSet(ht, "@10", strlen("@10"), (void *) "DAT10");
    htSet(ht, "@11", strlen("@11"), (void *) "DAT11");
    htSet(ht, "@12", strlen("@12"), (void *) "DAT12");
    htSet(ht, "@13", strlen("@13"), (void *) "DAT13");
    htSet(ht, "@14", strlen("@14"), (void *) "DAT14");
    htSet(ht, "@15", strlen("@15"), (void *) "DAT15");
    htSet(ht, "@16", strlen("@16"), (void *) "DAT16");
    htSet(ht, "@17", strlen("@17"), (void *) "DAT17");
    htSet(ht, "@18", strlen("@18"), (void *) "DAT18");
    htSet(ht, "@19", strlen("@19"), (void *) "DAT19");
    htSet(ht, "@20", strlen("@20"), (void *) "DAT20");

    htSet(ht, "test", strlen("test"), (void *) "hello, world!");

    htSet(ht, "测试", strlen("测试"), (void *) "测试");

    htOutput(ht);

    value = htGet(ht, "test", strlen("test"));
    if (value) {
        printf("test: %s\n", (const char *) value);
    }

    value = htGet(ht, "not-exists", strlen("not-exists"));
    if (value) {
        printf("not-exists: %s\n", (const char *) value);
    }

    htFree(ht);

    return 0;
}
