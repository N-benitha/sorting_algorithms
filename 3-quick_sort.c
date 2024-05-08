#include "sort.h"

/**
 * swap -  swaps the values of two pointers
 * @a: poniter 1
 * @b: pointer 2
 *
 * Return: nothing.
 */

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - divides an array into parts
 * @array: array
 * @size: size of the array
 * @low: lower part
 * @high: higher part
 *
 * Return: nothing.
 */

int partition(int *array, size_t size, int low, int high)
{
	int above, below;
	int *pivot = array + high;

	for (above = below = low; below <= high - 1;  below++)
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
	}
	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}

/**
 * quick_sort_helper - sorts the array's partitioned parts recursively
 * using quick sort method
 * @array: array
 * @size: size of the array
 * @low: lower
 * @high: higher
 *
 * Return: nothing.
 */

void quick_sort_helper(int *array, size_t size, int low, int high)
{
	int part;

	if (low < high)
	{
		part = partition(array, size, low, high);
		quick_sort_helper(array, size, low, part - 1);
		quick_sort_helper(array, size, part + 1, high);
	}
}

/**
 * quick_sort - sorts an array using quick sort
 * @array: array to sort
 * @size: size of the array
 *
 * Return: nothing.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort_helper(array, size, 0, size - 1);
}
