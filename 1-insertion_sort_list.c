#include <stdlib.h>
#include <stddef.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *        in ascending order using the insertion sort
 *@list: A double pointer to a doubly-linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *prev, *next, *head;

	if (!list || !(*list) || (*list)->next == NULL)
		return;

	head = *list;

	while (head)
	{
		next = head;
		prev = next->prev;
		while (prev && (prev->n > next->n))
		{

			swap_list(list, &prev, next);
			print_list((const listint_t *)*list);
		}

		head = head->next;
	}
}

/**
 * swap_list - Swaps the position of two nodes of a doubly linked list
 * @list: a double pointer to a doubly linked list
 * @prev: Double pointer to the node to be taken forward
 * @next: The node to bring backward
 */
void swap_list(listint_t **list, listint_t **prev, listint_t *next)
{
	(*prev)->next = next->next;
	if (next->next)
		next->next->prev = *prev;
	next->prev = (*prev)->prev;
	next->next = *prev;
	if ((*prev)->prev)
		(*prev)->prev->next = next;
	else
		*list = next;
	(*prev)->prev = next;
	*prev = next->prev;
}
