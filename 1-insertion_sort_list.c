#include "sort.h"

/**
 * insertion_sort - sorts a double linked list using insertion sort
 * @list: list to sort
 *
 * Return: nothing.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *point;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		point = current;
		while (point->prev != NULL && point->n < point->prev->n)
		{
			point->prev->next = point->next;
			if (point->next != NULL)
				point->next->prev = point->prev;
			point->next = point->prev;
			point->prev = point->next->prev;
			point->next->prev = point;
			
			if (point->prev != NULL)
				point->prev->next = point;
			else
				*list = point;
			print_list(*list);
		}
		current = current->next;
	}
}
