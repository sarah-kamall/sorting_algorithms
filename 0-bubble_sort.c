#include"sort.h"
/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int d;

	d = *a;
	*a = *b;
	*b = d;
}
/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
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
				swap_ints(&array[j + 1], &array[j]);
				print_array(array, size);
			}
		}
		if (!swapb)
			break;
	}
}

