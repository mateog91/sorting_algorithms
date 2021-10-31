#include "sort.h"

/**
 * counting_sort - Write a function that sorts an array of
 * integers in ascending order using the Counting sort algorithm
 * @array: array to sort
 * @size: size of array
 *
 * Description:
 * Prototype: void counting_sort(int *array, size_t size);
 * You can assume that array will contain only numbers >= 0
 * You are allowed to use malloc and free for this task
 * You’re expected to print your counting array once it is set up
 * (See example below)
 * This array is of size k + 1 where k is the largest number in array
 *
 * Return: Nothing
 */

void counting_sort(int *array, size_t size)
{
	int *count, *b;
	size_t i, k;

	k = array[0];
	for (i = 1; i < size - 1; i++)
	{
		if (array[i] > (int)k)
			k = array[i];
	}

	count = malloc(sizeof(size_t) * (k + 1));
	b = malloc(sizeof(array[0] * size));

	for (i = 0; i < k + 1; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		++count[array[i]];

	for (i = 1; i <= k; i++)
		count[i] = count[i] + count[i - 1];
	print_array(count, k + 1);

	for (i = size - 1; 1; i--)
	{
		b[--count[array[i]]] = array[i];
		if (i == 0)
			break;
	}

	for (i = 0; i < size; i++)
		array[i] = b[i];

	free(count);
	free(b);
}
