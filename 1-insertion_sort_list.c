#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *
 * @list: the input list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *insert, *cur = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
        	return;

	while (cur)
	{
		insert = cur;
		while (insert->prev && insert->n < insert->prev->n)
		{
			if (insert->next)
				insert->next->prev = insert->prev;

			insert->prev->next = insert->next;
			insert->next = insert->prev;
			insert->prev = insert->prev->prev;

			if (insert->prev)
				insert->prev->next = insert;
			else
				*list = insert;

			print_list(*list);
        	}
		cur = cur->next;	
	}
}
