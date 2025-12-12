#include "sort.h"

/**
 * lomuto_partition - Partitions sub-array around pivot using Lomuto scheme
 * @array: The array to sort
 * @low: Start index of sub-array
 * @high: End index of sub-array
 * @size: Total size of the array (for printing)
 *
 * Return: The pivot index after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
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
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
        }
    }

    if (i + 1 != high)
    {
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        print_array(array, size);
    }

    return i + 1;
}
/**
 * quick_sort_recursive - Recursively applies Quick Sort to sub-arrays
 * @array: The array to sort
 * @low: Start index of sub-array
 * @high: End index of sub-array
 * @size: Total size of the array (for printing)
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot_index = lomuto_partition(array, low, high, size);

        quick_sort_recursive(array, low, pivot_index - 1, size);
        quick_sort_recursive(array, pivot_index + 1, high, size);
    }
}
/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick Sort algorithm.
 * @array: Pointer to the array of integers to be sorted.
 * @size: The number of elements in the array.
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
