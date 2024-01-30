#include "backend.h"

/**
 * Initialize an empty linked list
 */
LIST ListNew(LIST* list, size_t EntrySize) {
	LIST instance = calloc(1, sizeof(list));
	*list = instance;

	instance->entrySize = EntrySize;
	return instance;
}

/**
 * Add a new node with data to the end of the list
 */
void ListAppend(LIST list, void* data) {
	NODE child;

	if ((child = (NODE) calloc(1, list->entrySize)) != NULL) {
		child->node = data;
		child->next = NULL;

		if (list->head == NULL) {
			list->head = child;
		}
		else {
			NODE current = list->head;
			while (current->next != NULL) {
				current = current->next;
			}

			current->next = child;
		}

		list->entries++;
	}
}

/**
 * Remove the last node from the list
 */
void ListRemoveLast(LIST list) {
	if (list->head != NULL) {
		if (list->entries == 1) {
			free(list->head);
			list->head = NULL;
		}
		else {
			NODE current = list->head,
				previous = NULL;

			while (current->next != NULL) {
				previous = current;
				current = current->next;
			}

			free(current);
			previous->next = NULL;
		}

		list->entries--;
	}
}

/**
 * Iterate over the list and apply a visitor function
 */
void ListIterate(LIST list, ListVisitorFn visitor) {
	for ( NODE current = list->head
		; current
		; current = current->next)
	{
		visitor(current->node);
	}
}

/**
 * Find an item in the list based on a comparison function
 */
NODE ListSearch(LIST list, ListComparatorFn comparator, void* target) {
	NODE found = NULL;

	for ( NODE current = list->head
		; current
		; current = current->next)
	{
		if (comparator(current->node, target) == 0) {
			found = current;
			goto finished;
		}
	}

finished:
	return found;
}

/**
 * Free the memory the list occupied.
 */
void ListFree(LIST list) {
	NODE next = NULL;

	for ( NODE current = list->head
		; current
		; current = next)
	{
		NODE next = current->next;
		free(current);
	}

	list->head = NULL;
	list->entrySize = 0;
	free(list);
}
