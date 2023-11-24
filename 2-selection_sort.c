#include"sort.h"
/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, indxmin;
	int min;

	for (i=0; i < size; i++)
	{
		min = INT_MAX;
		for (j = i; j < size; j++)
		{
			if (array[j] < min)
			{
				indxmin = j;
				min = array[j];
			}
		}
		if (indxmin != i)
		{
			swap_ints(&array[indxmin], &array[i]);
			print_array(array, size);
		}
	}
}


