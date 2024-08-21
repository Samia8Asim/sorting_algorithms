#include "sort.h"

/**
 * swaping - swaps Nodes
 * @list: Our List
 * @n: the input node
 * Return: listint_t
 */
listint_t *swaping(listint_t **list, listint_t *n)
{
	listint_t *f = n->prev, *s = n;

	f->next = s->next;
	if (s->next)
		s->next->prev = f;

	s->next = f;
	s->prev = f->prev;
	f->prev = s;
	if (s->prev)
		s->prev->next = s;
	else
		*list = s;

	return (s);
}

/**
 * cocktail_sort_list - sorts the list
 * @list: Our List
 */
void cocktail_sort_list(listint_t **list)
{
	int i;
	listint_t *node;

	if (!list || !*list)
		return;

	node = *list;

	do {
		i = 0;
		while (node && node->next)
		{
			if (node->n > node->next->n)
			{
				node = swaping(list, node->next);
				print_list(*list);
				i = 1;
			}
			node = node->next;
		}

		if (i == 0)
			break;

		i = 0;
		while (node && node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swaping(list, node);
				print_list(*list);
				i = 1;
			}
			else
				node = node->prev;
		}
	} while (i);
}
