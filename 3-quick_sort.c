#include "sort.h"
#include <stdio.h>
/**
 * partition - calculate the new partition array
 * @array: array of integers
 * @lo: lower value for start
 * @hi: highter value for end
 * @size: array element size
 * Return: int index pivot
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo;
	int j;
	int tmp;
	int tmp2;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (array[i] != array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[hi])
	{
		tmp2 = array[i];
		array[i] = array[hi];
		array[hi] = tmp2;
		print_array(array, size);
	}
	return (i);
}
/**
 * sort - making recursion for quick sort
 * @array: array of integers
 * @lo: start
 * @hi: end
 * @size: array element size
 */
void sort(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		sort(array, lo, p - 1, size);
		sort(array, p + 1, hi, size);
	}
}
/**
 * quick_sort - implement quick_sort algorithm
 * @array: array of integers
 * @size: array element size
 */
void quick_sort(int *array, size_t size)
{
	sort(array, 0, (int)size - 1, size);
}
