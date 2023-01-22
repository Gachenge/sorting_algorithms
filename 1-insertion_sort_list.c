#include "sort.h"

/**
  * sort - insertion sort linked list
  * @n1: first node
  * @n2: second node
  */

void swap(*n1, *n2)
{
	listint_t *temp;

	temp = n1->next;
	n

/**
  * insertion_sort_list - by insertion sort, sort a linked list
  * @list: the head of the list
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *h, *n1, *n2;

	for (h = *list; h->next; h = h->next)
	{
		n1 = h->next;
		n2 = h->prev;
		while (n2 && h->n < n2->n)
		{
			swap(n2, h);
			print_list(*list);
		}
	}
}
