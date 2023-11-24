#include"sort.h"
void swap_ints(int *a, int *b);
size_t partition(int low, int high, int *array, size_t siz);
void quickrec(int *array, int size, int low, int high);
void quick_sort(int *array, size_t size);
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
 * partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The starting index of the subset to order.
 * @high: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
size_t partition(int low, int high, int *array, size_t size)
{
	int  i, j;
	int pivot;

	pivot = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap_ints(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * quickrec - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index of the array partition to order.
 * @high: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void quickrec(int *array, int size, int low, int high)
{
	size_t part, siz;

	siz = size;
	if (low < high && low >= 0 && high < size)
	{
		part = partition(low, high, array, siz);
		quickrec(array, size, low, part - 1);
		quickrec(array, size, part + 1, high);
	}
}
/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	long int s;

	s = size;
	quickrec(array, s, 0, s - 1);
}
