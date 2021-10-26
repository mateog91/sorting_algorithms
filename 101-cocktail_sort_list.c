#include "sort.h"

/**
 * cocktail_sort_list -  sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 *
 * @list: Double pointer to the list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	size_t size, i, begin = 1, end;
	int flag;

	if (list == NULL || *list == NULL)
		return;
	size = _length(list);
	if (size < 2)
		return;
	end = size - 1;
	current = *list;
	do {
		flag = 0;
		for (i = begin; i <= end; i++)
		{
			if (current->n > current->next->n)
			{
				swap_left(list, current->next);
				print_list(*list);
				flag = 1;
			}
			else
				current = current->next;
		}
		current = current->prev;
		flag = 0;
		for (i = end; i > begin; i--)
		{
			if (current->n < current->prev->n)
			{
				swap_left(list, current);
				print_list(*list);
				flag = 1;
			}
			else
				current = current->prev;
		}

		begin++;
	} while (flag);
}

/**
 * swap_left - swaps the @node to the left
 *
 * @list: Double pointer to list
 * @node: Pointer to the node to swap
 *
 * Description:
 * Swipes the input @node to the left of the @list.
 * If first node is selected, no swapping is done.
 */
void swap_left(listint_t **list, listint_t *node)
{
	listint_t *before = node->prev;

	if (before == NULL)
		return;

	/* Remove Node */
	before->next = node->next;
	if (node->next != NULL)
		node->next->prev = before;

	/* Connect node */
	node->next = before;
	node->prev = before->prev;

	/* Connect new adjescents to node */
	before->prev = node;
	if (node->prev != NULL)
		node->prev->next = node;
	else
		*list = node;
}

/**
 * _length - finds lenght of list
 * @list: Input list
 *
 * Return: size of the list
 */
size_t _length(listint_t **list)
{
	size_t size = 1;
	listint_t *current = *list;

	while (current->next != NULL)
	{
		current = current->next;
		size++;
	}
	return (size);
}
