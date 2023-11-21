#include "sort.h"

/**
 * get_max_val - Get the maximum value in an array of ints.
 * @array: Array of ints.
 * @size: Size of the array.
 *
 * Return: The max value integer in the array.
 */
int get_max_val(int *array, int size)
{
	int get_max_val, x;

	for (get_max_val = array[0], x = 1; x < size; x++)
	{
		if (array[x] > get_max_val)
			get_max_val = array[x];
	}

	return (get_max_val);
}

/**
 * counting_sort - sorts an array of integers in ascending order
 * @array: the array of integers.
 * @size: the size of the array.
 *
 * Return: no return(void)
 */
void counting_sort(int *array, size_t size)
{
	int *counter;
	int *arr_sorted;
	int get_max_value, x;

	if (array == NULL || size < 2)
		return;

	arr_sorted = malloc(sizeof(int) * size);
	if (arr_sorted == NULL)
		return;
	get_max_value = get_max_val(array, size);
	counter = malloc(sizeof(int) * (get_max_value + 1));
	if (counter == NULL)
	{
		free(arr_sorted);
		return;
	}

	for (x = 0; x < (get_max_value + 1); x++)
		counter[x] = 0;
	for (x = 0; x < (int)size; x++)
		counter[array[x]] += 1;
	for (x = 0; x < (get_max_value + 1); x++)
		counter[x] += counter[x - 1];
	print_array(counter, get_max_value + 1);

	for (x = 0; x < (int)size; x++)
	{
		arr_sorted[counter[array[x]] - 1] = array[x];
		counter[array[x]] -= 1;
	}

	for (x = 0; x < (int)size; x++)
		array[x] = arr_sorted[x];

	free(arr_sorted);
	free(counter);
}
