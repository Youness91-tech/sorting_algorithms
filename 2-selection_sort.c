#include "sort.h"

/**
 * selection_sort - Ssorts an array of integers in ascending order
 * @array: array to sort
 * @size: The array size
 *
 * Return: void(no return)
 */
void selection_sort(int *array, size_t size)
{
	size_t x, y;
	size_t min_idx;
	int tmp;

	if (array == NULL || size <= 1)
		return;

	for (x = 0; x < size - 1; x++)
	{
		min_idx = x;

		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[min_idx])
				min_idx = y;
		}

		if (min_idx != x)
		{
			tmp = array[x];
			array[x] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}
	}
}
