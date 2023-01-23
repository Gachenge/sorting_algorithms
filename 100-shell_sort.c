#include "sort.h"

/**
 * swap - swap two elements of an array
 * @a: the first element
 * @b: the other
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - sort an array of integers using shell sort and Knuth sequence
 * @array: the array to sort
 * @size: size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;
	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;
	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap((array + j), array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
