#include "sort.h"
/**
 * @tab: is the array to travel
 * @n: is the number of variables in the array
 * 
 * Return: nothing
 */

void bubble_sort(int tab[], int n)
{
	int i, j, tmp;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
		}
	}
}