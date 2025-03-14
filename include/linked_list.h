#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct
{
    int size;
    struct Node *head;
    struct Node *tail;
} LinkedList;

LinkedList* create_list();
void insert_node(LinkedList *list, Node *node);
void print_list(LinkedList *list);

#endif
