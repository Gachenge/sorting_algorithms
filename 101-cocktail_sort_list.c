#include "sort.h"

/**
 * swap_node_for - swap two nodes in a doubly linked list moving forward
 * @h: pointer to the head node
 * @a: the pointer to the first node
 * @b: the second node
 */

void swap_node_for(listint_t **h, listint_t **a, listint_t **b)
{
	listint_t *temp = (*b)->next;

	if ((*b)->prev != NULL)
		(*b)->prev->next = temp;
	else
		*h = temp;
	temp->prev = (*b)->prev;
	(*b)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *b;
	else
		*a = *b;
	(*b)->prev = temp;
	temp->next = *b;
	*b = temp;
}

/**
 * swap_node_rev - swap two nodes moving backwards
 * @list: the pointer top the head node
 * @a: the pointer to the first node
 * @b: pointer to other node
 */

void swap_node_rev(listint_t **list, listint_t **a, listint_t **b)
{
	listint_t *temp = (*b)->prev;

	if ((*b)->next != NULL)
		(*b)->next->prev = temp;
	else
		*a = temp;
	temp->next = (*b)->next;
	(*b)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *b;
	else
		*list = *b;
	(*b)->next = temp;
	temp->prev = *b;
	*b = temp;
}

/**
 * cocktail_sort_list - sort a doubly linked list using cocktail sort
 * @list: pointer to the head node
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *curr, *tail;
	bool swapped = false;

	if (!list || !*list || (*list)->next == NULL)
		return;
	tail = *list;
	while (tail)
		tail = tail->next;

	while (!swapped)
	{
		swapped = true;
		for (curr = *list; curr != tail; curr = curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_node_for(list, &tail, &curr);
				print_list(*list);
				swapped = false;
			}
		}
		for (curr = curr->prev; curr != *list;
				curr = curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_node_rev(list, &tail, &curr);
				print_list(*list);
				swapped = false;
			}
		}
	}
}
