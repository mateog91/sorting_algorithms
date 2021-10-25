#include "sort.h"

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    int partition_index;

    if (low < high)
    {
        partition_index = partition(array, low, high, size);

        quick_sort_recursive(array, low, partition_index - 1, size);
        quick_sort_recursive(array, partition_index + 1, high, size);
    }
}

int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = (low - 1), j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap_array(array, i, j);
        }
    }
    swap_array(array, i + 1, high);
    /*printf("low [%li]\nhigh [%li]\ni [%li]\nj [%li]\n", low, high, i, j);*/
    print_array(array, size);
    return (i + 1);
}

void swap_array(int *array, int idx1, int idx2)
{
    int temp = array[idx1];

    array[idx1] = array[idx2];
    array[idx2] = temp;
}

void quick_sort(int *array, size_t size)
{
    quick_sort_recursive(array, 0, (int)size - 1, size);
}