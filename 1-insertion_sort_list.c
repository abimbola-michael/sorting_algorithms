#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *key;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (current = (*list)->next; current != NULL; current = current->next)
	{
		key = current;
		while (key->prev != NULL && key->prev->n > key->n)
		{
			if (key->next != NULL)
				key->next->prev = key->prev;
			key->prev->next = key->next;
			key->next = key->prev;
			key->prev = key->prev->prev;
			key->next->prev = key;
			if (key->prev == NULL)
				*list = key;
			print_list((const listint_t *)*list);
		}
	}
}
