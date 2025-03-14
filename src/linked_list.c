#include <stdio.h>
#include <stdlib.h>
#include "../include/linked_list.h"

LinkedList* create_list()
{
    LinkedList *list = malloc(sizeof(LinkedList));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void insert_node(LinkedList *list, Node *node)
{
    node = malloc(sizeof(Node));

    if ( list->head == NULL )
    {
        list->head = node;
        list->tail = node;
        node->next = NULL;
        node->prev = NULL;
        ++list->size;
    }
    else
    {
        node->next = list->head;
        node->prev = NULL;
        list->head->prev = node;
        list->head = node;
        ++list->size;
    }
    return;
}

void destroy_list(LinkedList *list)
{
    int i;
    for ( i = 0; i < list->size; ++i )
    {
        free(list->head);
    }
    free(list);
}
