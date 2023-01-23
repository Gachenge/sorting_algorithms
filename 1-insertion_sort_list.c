#include "sort.h"

/**
 * swap_node - swap two nodes in doubly linked list
 * @h: pointer to the head node
 * @n1: pointer to the first node
 * @n2: second node
 */

void swap_node(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sort a linked list by insertion sort algorithm
 * @list: pointer to the head node
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp, *node;

	if (!list || !*list || (*list)->next == NULL)
		return;
	for (curr = (*list)->next; curr; curr = temp)
	{
		temp = curr->next;
		node = curr->prev;
		while (node && curr->n < node->n)
		{
			swap_node(list, &node, curr);
			print_list(*list);
		}
	}
}
