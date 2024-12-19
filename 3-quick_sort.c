#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * partition - Lomuto partition scheme
 * @array: The array to sort
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Total size of the array (for printing)
 *
 * Return: Index of the pivot after partitioning
 */
int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;

    int j;
    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }
    if (i + 1 != high)
    {
        swap(&array[i + 1], &array[high]);
        print_array(array, size);
    }
    return (i + 1);
}

/**
 * quick_sort_recursive - Recursively sorts partitions of the array
 * @array: The array to sort
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Total size of the array (for printing)
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = partition(array, low, high, size);

        quick_sort_recursive(array, low, pi - 1, size);
        quick_sort_recursive(array, pi + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers using the Quick sort algorithm
 * @array: The array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
