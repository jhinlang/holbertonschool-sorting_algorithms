#include "sort.h"
/**
 * swap_nodes - Swap two adjacent nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @left: Node on the left
 * @right: Node on the right (must be left->next)
 */
static void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	listint_t *prev, *next;

	if (left == NULL || right == NULL || right->prev != left)
	{
		return;
	}

	prev = left->prev;
	next = right->next;

	if (prev != NULL)
	{
		prev->next = right;
	}
	else
	{
		*list = right;
	}

	if (next != NULL)
	{
		next->prev = left;
	}

	right->prev = prev;
	right->next = left;
	left->prev = right;
	left->next = next;
}

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	current = (*list)->next;
	while (current != NULL)
	{
		tmp = current;

		while (tmp->prev != NULL && tmp->prev->n > tmp->n)
		{
			swap_nodes(list, tmp->prev, tmp);
			print_list(*list);
		}
		current = current->next;
	}
}
