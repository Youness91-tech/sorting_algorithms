#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, x, y;
	int temp;

	while (gap < size)
		gap = gap * 3 + 1;

	for (gap = (gap - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		for (x = gap; x < size; x++)
		{
			temp = array[x];
			y = x;
			while (y >= gap && array[y - gap] > temp)
			{
				array[y] = array[y - gap];
				y -= gap;
			}
			array[y] = temp;
		}
		print_array(array, size);
	}
}
