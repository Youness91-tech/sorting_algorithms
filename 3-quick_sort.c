#include "sort.h"

/**
 * ints_swap - Swap two integers in an array.
 * @a: The first intgrs
 * @b: The second intgrs
 **/
void ints_swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partn - split array around a pivot
 * @arr: The array
 * @st_elem: The first element
 * @last_elem: The last element
 * @size: Array size
 * Return: i integer
 */
int partn(int *arr, int st_elem, int last_elem, size_t size)
{
	int pivot = arr[last_elem];
	int i = st_elem;
	int j;

	for (j = st_elem; j < last_elem; j++)
	{
		if (arr[j] <= pivot)
		{
			ints_swap(&arr[i], &arr[j]);
			if (i != j)
				print_array(arr, size);
			i++;
		}
	}
	ints_swap(&arr[i], &arr[last_elem]);
	if (i != j)
		print_array(arr, size);
	return (i);
}

/**
 * lomuto_sort - sorts a part of the list
* @arr: array to be sorted
 * @st_elem: first element
 * @last_elem: last element
 * @size: Array size
 * Return: no return
 */
void lomuto_sort(int *arr, int st_elem, int last_elem, size_t size)
{
	int pivot;

	if (st_elem < last_elem)
	{
		pivot = partn(arr, st_elem, last_elem, size);
		lomuto_sort(arr, st_elem, pivot - 1, size);
		lomuto_sort(arr, pivot + 1, last_elem, size);
	}
}

/**
 * quick_sort - quick sort method of an array
 * @array: array to be sorted
 * @size: array size
 * Return: no return
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	lomuto_sort(array, 0, size - 1, size);
}
