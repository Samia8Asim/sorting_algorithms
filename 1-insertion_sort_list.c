#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *
 * @list: the input list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node, *cur, *back;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	cur = (*list)->next;

	while (cur)
	{
		node = cur;
		while (node->prev && node->n < node->prev->n)
		{
			back = node->prev;
			back->next = node->next;

			if (node->next)
				node->next->prev = back;

			node->next = back;
			node->prev = back->prev;
			back->prev = node;

			if (node->prev)
				node->prev->next = node;
			else
				*list = node;

			print_list((const listint_t *)*list);
		}
		cur = cur->next;
	}
}
