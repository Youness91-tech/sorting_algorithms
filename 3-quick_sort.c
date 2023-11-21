#include "sort.h"

/**
 * int_swap - swaps two integers
 * @a: The first integer
 * @b: The second integer
 **/
void int_swap(int *a, int *b)
{
        int tmp = *a;
        *a = *b;
        *b = tmp;
}

/**
 * lomuto_partition - splits array around a pivot
 * @arr: the array
 * @elem_one: the first element
 * @elem_two: the last element
 * @size: the size of array
 * Return: integer
 */
int lomuto_partition(int *arr, size_t size, int elem_one, int elem_two)
{
        int pivot = arr[elem_two];
        int x = elem_one;
        int y;

        for (y = elem_one; y < elem_two; y++)
        {
                if (arr[y] <= pivot)
                {
                        int_swap(&arr[x], &arr[y]);
                        if (x != y)
                                print_array(arr, size);
                        x++;
                }
        }
        int_swap(&arr[x], &arr[elem_two]);
        if (x != y)
                print_array(arr, size);
        return (x);
}

/**
 * lomuto_sort - sorts a part of the list
 * @arr: array to sort
 * @elem_one: the first element
 * @elem_two: the last element
 * @size: the size of array
 * Return: no return
 */
void lomuto_sort(int *arr, int elem_one, int elem_two, size_t size)
{
        int pivot;

        if (elem_one < elem_two)
        {
                pivot = lomuto_partition(arr, elem_one, elem_two, size);
                lomuto_sort(arr, elem_one, pivot - 1, size);
                lomuto_sort(arr, pivot + 1, elem_two, size);
        }
}

/**
 * quick_sort - quick sort method of an array
 * @array: array to sort
 * @size: the size of array
 * Return: no return
 */
void quick_sort(int *array, size_t size)
{
        if (size < 2)
                return;
        lomuto_sort(array, 0, size - 1, size);
}
