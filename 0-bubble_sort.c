#include "sort.h"
/**
 * @tab: is the array to travel
 * @n: is the number of variables in the array
 * 
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	int i, j, tmp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}