#include "sort.h"

/**
 * swaping - swaps Nodes
 * @list: Our List
 * @f: First node
 * @s: Second node
 */
void swaping(listint_t **list, listint_t *f, listint_t *s)
{
	if (f->prev)
		f->prev->next = s;
	else
		*list = s;

	if (s->next)
		s->next->prev = f;

	f->next = s->next;
	s->next = f;
	f->prev = s;
	s->prev = f->prev;

	print_list(*list);
}

/**
 * cocktail_sort_list - sorts the list
 * @list: Our List
 */
void cocktail_sort_list(listint_t **list)
{
	int i;
	listint_t *node, *temp;

	if (!list || !*list)
		return;

	do
	{
		i = 0;
		node = *list;

		while (node && node->next)
		{
			if (node->n > node->next->n)
			{
				swaping(list, node, node->next);
				print_list(*list);
				i = 1;
			}
			node = node->next;
		}

		if (i == 0)
			break;

		i = 0;
		temp = node ? node->prev : *list;
		while (temp && temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				swaping(list, temp->prev, temp);
				print_list(*list);
				i = 1;
			}
			temp = temp->prev;
		}
	} while (i);
}
