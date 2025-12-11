#include "sort.h"
/**
 * bubble_sort - function to make a sort
 *@array: is the array to travel
 *@size: is the number of variables in the array
 *
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;
	int swapped;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;

				swapped = 1;

				print_array(array, size);
			}
		}

		if (!swapped)
		{
			break;
		}
	}
}
