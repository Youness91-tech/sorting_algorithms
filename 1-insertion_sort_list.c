#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order
 * @list: list to sort
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	/* init Nds */
	listint_t *nd = NULL;
	listint_t *hlpr = NULL;

	if (!list || !*list || !(*list)->next)
		return;

	nd = *list;
	nd = nd->next;

	while (nd != NULL)
	{
		while (nd->prev && nd->n < (nd->prev)->n)
		{
			/* swp nds */
			hlpr = nd;

			if (nd->next)
				(nd->next)->prev = hlpr->prev;

			(nd->prev)->next = hlpr->next;
			nd = nd->prev;
			hlpr->prev = nd->prev;
			hlpr->next = nd;

			if (nd->prev)
				(nd->prev)->next = hlpr;

			nd->prev = hlpr;

			if (hlpr->prev == NULL)
				*list = hlpr;

			print_list(*list);
			nd = nd->prev;
		}
		/* isrt nd */
		nd = nd->next;
	}
}
