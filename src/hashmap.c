#include "hashmap.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * Initialize the HashMap
 */

HashMap* init_hashmap()
{
    HashMap* map = malloc(sizeof(HashMap));
    
    // If we fail to allocate memory, return NULL
    if ( map == NULL )
    {
        return NULL;
    }
    
    // Set initial length to zero, nothing being added yet
    map->length = 0;
    // Set initial capacity (24)
    map->capacity = INITIAL_CAPACITY;
    // Allocate memory for entry buckets (pointer to an array of pointers)
    map->entry_buckets = calloc(map->capacity, sizeof(HashEntry*));
    
    // If we fail to allocate memory, free the map and return NULL
    if ( map->entry_buckets == NULL )
    {
        free(map);
        return NULL;
    }
    return map;
}

/*
 * Add a new entry to the HashMap, using simple chaining
 * The caller will be responsible for freeing the Node.
 * See node.c for Node freeing.
 */
int add_entry(HashMap* map, uint8_t key, int data)
{
    // hash current key and get the new index
    uint32_t index = hash_index(key, map->capacity);

    // Set initial 'current' entry_bucket
    HashEntry* current = map->entry_buckets[index];
    HashEntry* previous = NULL;
    
    /*
     * Allocate memory for new entry and check for
     * failure. If it fails we return here
     */

    
    if (current == NULL) // Bucket is empty, add new_entry here
    {
        HashEntry *new_entry = malloc(sizeof(HashEntry));
        if (new_entry == NULL)
        {
            printf("Failed to allocate memory for HashEntry!\n");
            return -1;
        }

        new_entry->key = key;
        new_entry->data = data;
        new_entry->next = NULL;
        map->entry_buckets[index] = new_entry;

        ++map->length;
        return 0;
    }
    
    while (current != NULL)
    {
        // Key already exists, return error
        if (current->key == key)
        {
            printf("Key already exists!\n");
            return -1;
        }

        /*
         * Here we copy current to previous because:
         *
         *  Once current reaches NULL, the loop will end,
         *  and we would lose access to the last non-NULL
         *  entry inside this bucket. So we copy the current
         *  to ensure we have the final entry, which is the
         *  one we want to link to new_entry.
         * 
         */

        // Copy current FIRST then go to the next node
        previous = current;
        current = current->next;
    }
    
    HashEntry* new_entry = malloc(sizeof(HashEntry));
    if (new_entry == NULL) 
    {
        printf("Failed to allocate memory for HashEntry!\n");
        return -1;
    }
    new_entry->key = key;
    new_entry->data = data;
    new_entry->next = NULL;
    previous->next = new_entry; // **Append the new_entry
    ++map->length;
    return 0;
}

int destroy_hashmap(HashMap* map)
{
    for (uint32_t i = 0; i < map->capacity; ++i)
    {
        HashEntry* temp = map->entry_buckets[i];
        while (temp != NULL)
        {
            HashEntry* prev = temp;
            temp = temp->next;
            free(prev);
            prev = NULL;
        }
    }
    free(map->entry_buckets);
    map->entry_buckets = NULL;
    free(map);
    map = NULL;
    return 0;
}

uint32_t hash_index(uint8_t key, uint32_t capacity)
{
    return key % capacity;
}