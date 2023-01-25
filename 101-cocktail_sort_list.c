#include "sort.h"

/**
 * swap_node_for - swap nodes moving forwards
 * @list: the pointer to the head node
 * @tail: the last node
 * @curr: the current node
 */

void swap_node_for(listint_t **list, listint_t **tail, listint_t **curr)
{
	listint_t *temp = (*curr)->next;

	if ((*curr)->prev != NULL)
		(*curr)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*curr)->prev;
	(*curr)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *curr;
	else
		*tail = *curr;
	(*curr)->prev = temp;
	temp->next = *curr;
	*curr = temp;
}

/**
 * swap_node_prev - swap nodes moving back
 * @list: the head node pointer
 * @tail: the end node pointer
 * @curr: the current node pointer
 */

void swap_node_prev(listint_t **list, listint_t **tail, listint_t **curr)
{
	listint_t *temp = (*curr)->prev;

	if ((*curr)->next != NULL)
		(*curr)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*curr)->next;
	(*curr)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *curr;
	else
		*list = *curr;
	(*curr)->next = temp;
	temp->prev = *curr;
	*curr = temp;
}

/**
 * cocktail_sort_list - sort a doubly linked list using cocktail sort
 * @list: the head node pointer
 */

void cocktail_sort_list(listint_t **list)
{
	bool swap = false;
	listint_t *curr, *tail;

	if (!list || !*list || (*list)->next == NULL)
		return;

	tail = *list;
	while (tail->next != NULL)
		tail = tail->next;

	while (swap == false)
	{
		swap = true;
		for (curr = *list; curr != tail; curr = curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_node_for(list, &tail, &curr);
				print_list(*list);
				swap = false;
			}
		}
		for (curr = tail; curr != *list; curr = curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_node_prev(list, &tail, &curr);
				print_list(*list);
				swap = false;
			}
		}
	}
}
