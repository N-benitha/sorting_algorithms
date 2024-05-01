#include "sort.h"

/**
 * bubble_sort - sorts an array using bubble sort
 * @array: array to sort
 * @size: size of the array
 *
 * Return: nothing.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if (size <= 1 || array == NULL)
		return;

	for (j = 0; j < size; j++)
	{
		for (i = 0; i < size - j - 1; i++)
		{
			if (array[i] >= array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
