#include "sort.h"

void swap(listint_t **ll, listint_t **node1, listint_t *node2);

/**
 * swap - function to swap nodes
 * @ll: input linked list
 * @node1: node 1
 * @node2: node 2
 */

void swap(listint_t **ll, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;

	if ((*node1)->prev)
		(*node1)->prev->next = node2;
	else
		*ll = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - a function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *key, *current, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (current = (*list)->next; current != NULL; current = current->next)
	{
		key = current;
		prev = current->prev;
		while (key->prev != NULL && key->prev->n > key->n)
		{
			swap(list, &prev, current);
			print_list((const listint_t *)*list);
		}
	}
}
