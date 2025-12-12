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
	int i = low, j, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != high)
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i);
}

/**
 * quicksort_rec - Recursive part of quick sort
 * @array: array of integers
 * @low: lowest index
 * @high: highest index
 * @size: array size
 */
void quicksort_rec(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		quicksort_rec(array, low, pivot_index - 1, size);
		quicksort_rec(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: Pointer to array
 * @size: Size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort_rec(array, 0, size - 1, size);
}
