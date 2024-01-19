#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *
 * @list: the input list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node, *cur = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
        	return;

	while (cur)
	{
		node = cur;
		while (node->prev && node->n < node->prev->n)
		{
			if (node->next)
				node->next->prev = node->prev;

			node->prev->next = node->next;
			node->next = node->prev;
			node->prev = node->prev->prev;

			if (node->prev)
				node->prev->next = node;
			else
				*list = node;

			print_list(*list);
        	}
		cur = cur->next;	
	}
}
