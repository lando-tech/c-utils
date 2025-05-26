#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdint.h>

#define INITIAL_CAPACITY 24

typedef struct HashEntry
{
    int data;
    uint8_t key;
    struct HashEntry *next;
} HashEntry;

typedef struct HashMap
{
    HashEntry **entry_buckets;
    uint32_t capacity;
    uint32_t   length;
} HashMap;

HashMap* init_hashmap(void);
uint32_t get_length(HashMap* map);
struct Node* get_value(HashMap* map, uint8_t key);
int add_entry(HashMap* map, uint8_t key, int data);
void remove_entry();
int destroy_hashmap(HashMap* map);
uint32_t hash_index(uint8_t key, uint32_t capacity);

#endif