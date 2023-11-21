#include "sort.h"

/**
 * swap_nds - Swaps two nodes
 * @first_node: the first node
 * @second_node: the last  node
 * @head: the head of list
 *
 * Return: No return
 */

void swap_nds(listint_t *first_node, listint_t *second_node, listint_t **head)
{
	listint_t *temp;

	temp = first_node->prev;
	if (temp)
		temp->next = second_node;
	second_node->prev = temp;
	first_node->prev = second_node;
	first_node->next = second_node->next;
	second_node->next = first_node;
	if (first_node->next != NULL)
		first_node->next->prev = first_node;
	if (second_node->prev == NULL)
		*head = second_node;
	print_list(*head);
}

/**
 * cocktail_sort_list -  sorts a doubly linked list of
 * integers in ascending order
 * @list: the pointer to the head of the doubly linked list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	int sorted = 1;
	int begin = 0, finish = 0;
	int current_idx;

	if (list == NULL)
		return;
	temp = *list;
	while (temp->next != NULL)
		temp = temp->next, finish++;
	temp = *list;
	while (sorted == 1)
	{
		current_idx = begin;
		while (current_idx < finish)
		{
			if (temp->n > temp->next->n)
			{
				swap_nds(temp, temp->next, list);
				sorted = 1;
			}
			else
				temp = temp->next;
			current_idx++;
		}
		current_idx = finish;
		sorted = 0;
		while (current_idx > begin)
		{
			if (temp->n < temp->prev->n)
			{
				swap_nds(temp->prev, temp, list);
				sorted = 1;
			}
			else
				temp = temp->prev;
			current_idx--;
		}
		begin++;
	}
}
