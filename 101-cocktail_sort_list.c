#include "sort.h"


/**
 * swap_with_ahead - Swap current node and next node positions.
 * @list: Double pointer to the head of the linked list containing the nodes.
 * @tail: Double pointer to the tail of the linked list containing the nodes.
 * @ptr: Pointer to the current node.
 */
void swap_with_ahead(listint_t **list, listint_t **tail, listint_t **ptr)
{
	listint_t *c = *ptr;
	listint_t *n = (*ptr)->next;

	if (c->prev != NULL)
		c->prev->next = n;
	else
		*list = n;

	n->prev = c->prev;
	c->next = n->next;

	if (n->next != NULL)
		n->next->prev = c;
	else
		*tail = c;

	c->prev = n;
	n->next = c;
	*ptr = n;
}

/**
 * swap_with_prev - Swap current node and previous nodes' positions.
 * @list: Double pointer to the head of the linked list containing the nodes.
 * @tail: Double pointer to the tail of the linked list containing the nodes.
 * @ptr: Pointer to the current node.
 */
void swap_with_prev(listint_t **list, listint_t **tail, listint_t **ptr)
{
	listint_t *c = *ptr;
	listint_t *p = (*ptr)->prev;

	if (c->next != NULL)
		c->next->prev = p;
	else
		*tail = p;

	p->next = c->next;
	c->prev = p->prev;
	if (p->prev != NULL)
		p->prev->next = c;
	else
		*list = c;

	c->next = p;
	p->prev = c;
	*ptr = p;
}

/**
 * cocktail_sort_list - Sort a doubly linked list of integers
 *			using the Cocktail shaker sort algorithm.
 * @list: Double pointer to the head of the list.
 *
 * Description: The integers are sorted in ascending order.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *shaker, *tail;
	int shaken = 0;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL; tail = tail->next)
		;

	while (!shaken)
	{
		shaken = 1;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_with_ahead(list, &tail, &shaker);
				print_list(*list);
				shaken = 0;
			}
		}

		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_with_prev(list, &tail, &shaker);
				print_list(*list);
				shaken = 0;
			}
		}
	}
}

