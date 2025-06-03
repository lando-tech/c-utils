#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdint.h>

#define INITIAL_CAPACITY 24

typedef struct HashEntry
{
    int data;
    int key;
    struct HashEntry *next;
} HashEntry;

typedef struct HashMap
{
    HashEntry **entry_buckets;
    size_t capacity;
    size_t   length;
} HashMap;

HashMap* hashmap_init(void);
size_t hm_get_length(HashMap* map);
struct Node* hm_get_item(HashMap* map, int key);
int hm_add_entry(HashMap* map, int key, int data);
int hm_remove_item(HashMap* map, int key);
int hashmap_destroy(HashMap* map);
size_t hash_index(int key, size_t capacity);

#endif