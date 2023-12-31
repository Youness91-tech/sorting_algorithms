#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nds(listint_t *first_node, listint_t *second_node, listint_t **head);
int get_max_val(int *array, int size);
void counting_sort(int *array, size_t size);
void ints_swap(int *a, int *b);
int partn(int *arr, int st_elem, int last_elem, size_t size);
void lomuto_sort(int *arr, int st_elem, int last_elem, size_t size);
void quick_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);

#endif
