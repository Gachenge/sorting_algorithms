#include "sort.h"
/**
 * swap - swap two elements
 * @a: the first
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
 * partition - lomuto partition
 * @array: the araay to partition
 * @size: the size of the partition
 * @left: start index
 * @right: last index
 * Return: The partition
 */

int partition(int *array, size_t size, int left, int right)
{
	int above, below, *pivot;

	pivot = array + right;
	above = below = left;
	while (below < right)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
		below++;
	}
	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}

/**
 * sort - recursive function to sort an array using quick sort
 * @array: the array
 * @size: the size of the array
 * @left: start
 * @right: the end
 */

void sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = partition(array, size, left, right);
		sort(array, size, left, part - 1);
		sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - sort an array using quick sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{

	if (!array || size < 2)
		return;
	sort(array, size, 0, size - 1);
}
