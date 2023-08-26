#include "sort.h"

/**
 * swap_with_prev - Swap current node and previous nodes' positions.
 * @t: Pointer to the current node
 */
void swap_with_prev(listint_t **t)
{
	listint_t *c = *t;
	listint_t *p = (*t)->prev;

	c->prev = p->prev;
	if (p->prev != NULL)
		p->prev->next = c;

	p->next = c->next;
	if (c->next != NULL)
		c->next->prev = p;

	p->prev = c;
	c->next = p;
}

/**
 * insertion_sort_list - Sort a doubly linked list of integers
 *		using the insertion sort.
 * @list: Pointer to the head of the linked list.
 *
 * Description: The integers are arranged in ascending order.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *t, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	t = (*list)->next;

	while (t != NULL)
	{
		current = t;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			swap_with_prev(&current);

			if (current->prev == NULL)
				*list = current;
			print_list(*list);
		}
		t = t->next;
	}
}
