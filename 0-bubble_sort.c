#include <stdio.h>
#include <stddef.h>

/**
 * bubble_sort - Sorts an array of integers in ascending order using Bubble Sort
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp;
    int swapped;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;


                for (size_t k = 0; k < size; k++)
                {
                    printf("%d", array[k]);
                    if (k < size - 1)
                        printf(", ");
                }
                printf("\n");
            }
        }
        if (!swapped)
            break;
    }
}
