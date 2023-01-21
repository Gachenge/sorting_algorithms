#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *ls = *list;
	listint_t *temp;
	int i, j, len;

	len = 0;
	while (ls)
	{
		ls = ls->next;
		len++;
	}
	for (i = 1; i < len; i++)
	{
		temp = ls[i];
		j = i - 1;
		while(j > 0 && ls[i] > temp)
		{
			ls[j + 1] = ls[j];
			j--;
		}
		ls[j + 1] = temp;
	}
}
