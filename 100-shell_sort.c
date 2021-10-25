#include "sort.h"
/**
 * _pow - returns the value of x raised to the power of y
 * @x: input value of exponential base
 * @y: input value for exponent
 *
 * Return: Interger of @x to the power of @y
 */
int _pow(int x, int y)
{
	/* Base Case */
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);

	/* Recursive Case */
	return (x * _pow(x, (y - 1)));
}
/**
 * shell_sort -  function that sorts an array of integers in ascending order
 *  using the Shell sort algorithm, using the Knuth sequence
 *
 * @array: Pointer to the input array
 * @size: size of array
 *
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{

	size_t i, j, gap, n;

	if (array == NULL)
		return;
	if (size < 2)
	{
		print_array(array, size);
		return;
	}
	n = size / 3;
	if (size < 6)
		n = 2;
	while (1)
	{
		n--;
		if (n < 1)
			break;

		gap = (_pow(3, n) - 1) / 2;
		if (gap > size)
		{

			continue;
		}

		for (i = gap; i < size; i++)
		{
			int temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];

			array[j] = temp;
		}
		print_array(array, size);
	}
}
