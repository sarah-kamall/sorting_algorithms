#include"sort.h"

/**
 * func to 
 */
void swap(int *x, int *y)
{
	int d;

	d = *x;
	*x = *y;
	*y = d;
}
void bubble_sort(int *array, size_t size)
{
	size_t i, j, swapb;

	swapb = 0;
	for (i = 0; i < size - 1; i++)
	{
		swapb = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swapb = 1;
				swap(&array[j + 1], &array[j]);
				print_array(array, size);
			}
		}
		if (!swapb)
			break;
	}
}

