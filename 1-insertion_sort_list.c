#include "sort.h"

/**
 * insertion_sort_list - sort a linked list by insertion
 * @list: the list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp, *node;

	for (curr = *list; curr->next; curr = curr->next)
	{
		node = *list;
		temp = curr->prev;

		while (temp && (temp->n > node->n))
		{
			temp->next = temp;
			temp = temp->prev;
		}
		temp->next = node;
	}
}
