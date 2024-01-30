#pragma once
#include "backend.h"

// A generic structure
typedef struct node_t { struct node_t* next; void* node; } node, *NODE;

// A list for connections
// typedef struct client_node_t { struct client_node_t* next; CLIENT node; } client_node, *CLIENT_NODE;

// Linked list structure
typedef struct linked_list_t { NODE head; size_t entrySize, entries; } list, *LIST;

typedef void (*ListVisitorFn)(void *);
typedef int (*ListComparatorFn)(const void *, const void*);

// Function to initialize an empty linked list
LIST ListNew(LIST* list, size_t EntrySize);

// Function to add a new node with data to the end of the list
void ListAppend(LIST list, void* data);

// Function to remove the last node from the list
void ListRemoveLast(LIST list);

typedef void (*ListVisitorFn)(void *);
typedef int (*ListComparatorFn)(const void *, const void*);

// Function to iterate over the list and apply a visitor function
void ListIterate(LIST list, ListVisitorFn visitor);

// Function to find an item in the list based on a comparison function
NODE ListSearch(LIST list, ListComparatorFn comparator, void* target);

// Free memory occupied by a list pointer.
void ListFree(LIST list);
