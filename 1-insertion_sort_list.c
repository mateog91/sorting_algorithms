#include "sort.h"
#include <stdio.h>
/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 *
 * @list: Double linked list to be ordered
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *c_outer = *list;
	/* Edge case for lists with 0 or 1 element*/
	if (*list == NULL || c_outer->next == NULL)
	{
		print_list(*list);
		return;
	}
	/* Recorrer hasta el final de la lista */
	while (c_outer->next != NULL)
	{

		/* Comparar si el siguiente es menor al actual */
		if (c_outer->n > c_outer->next->n)

		/* Si: Intercambiar */
		{
			swap(list, c_outer->next);
		}

		/* Sino: Avanzar en la lista */
		else
			c_outer = c_outer->next;
	}
}

/**
 * swap - swaps numbers
 *
 * @list: list of the items
 * @c_inner: pointer to the node to swap.
 *
 */
void swap(listint_t **list, listint_t *c_inner)
{
	/* Remover el siguiente de la lista y guardar en temporal de origen */
	/*current = current->prev;*/

	while (c_inner->prev != NULL && c_inner->n < c_inner->prev->n)
	{
		/* REMOVE */
		c_inner->prev->next = c_inner->next;

		if (c_inner->next != NULL)
			c_inner->next->prev = c_inner->prev;

		/* insert node to new position*/

		c_inner->next = c_inner->prev;
		c_inner->prev = c_inner->prev->prev;

		/* Connect Adjacent nodes to node */
		c_inner->next->prev = c_inner;

		if (c_inner->prev == NULL)
			*list = c_inner;
		else
			c_inner->prev->next = c_inner;

		print_list(*list);
	}
}
/* Insert at the begginning of list*/

/**
 * remove - unction that deletes the node at index index of a
 * listint_t linked list.
 * @node: Double pointer to first element of the list
 * @index: Number of node to delete
 *
 * Return:
 * Next node
 */
