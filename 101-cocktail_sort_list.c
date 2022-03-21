#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list
 *      of integers in ascending order using the
 *      `Cocktail shaker sort algorithm`
 * @list: A linked list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node, *tail;
	int sorted = 0;

	if (!list || !(*list) || !((*list)->next))
		return;

	tail = *list;
	for (; tail->next;)
		tail = tail->next;

	while (sorted == 0)
	{
		sorted = 1;
		node = *list;
		for (; node != tail; node = node->next)
		{
			if (node->n > node->next->n)
			{
				swap_forward(list, &tail, &node);
				print_list((const listint_t *)*list);
				sorted = 0;
			}
		}
		node = node->prev;
		for (; node != *list; node = node->prev)
		{
			if (node->n < node->prev->n)
			{
				swap_backward(list, &tail, &node);
				print_list((const listint_t *)*list);
				sorted = 0;
			}
		}
	}
}

/**
 * swap_forward - Swaps the position of two nodes of a doubly linked list
 *
 * @list: A double pointer to a doubly linked list
 * @tail: A double pointer to the tail of a doubly linked list
 * @node: A double pointer to the node to move forward
 */
void swap_forward(listint_t **list, listint_t **tail, listint_t **node)
{
	listint_t *tmp = (*node)->next;

	if ((*node)->prev)
		(*node)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*node)->prev;
	(*node)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *node;
	else
		*tail = *node;
	(*node)->prev = tmp;
	tmp->next = *node;
	*node = tmp;
}

/**
 * swap_backward- Swaps the position of two nodes of a doubly linked list
 *
 * @list: A double pointer to doubly linked list
 * @tail: Double pointer to the tail of a doubly linked list (listint_t)
 * @node: A double pointer to the node to move backward
 */
void swap_backward(listint_t **list, listint_t **tail, listint_t **node)
{
	listint_t *tmp = (*node)->prev;

	if ((*node)->next)
		(*node)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*node)->next;
	(*node)->prev = tmp->prev;
	if (tmp->prev)
		tmp->prev->next = *node;
	else
		*list = *node;
	(*node)->next = tmp;
	tmp->prev = *node;
	*node = tmp;
}
