#include "sort.h"
/**
 * split - Find the position of the pivot element
 * @array: The array to sort
 * @left: The first element of the array
 * @right: The last element of the array
 * @size: The array size
 *
 * Return: The pivot position
 */
int split(int *array, int left, int right, size_t size)
{
	int i = left - 1, j;
	int pivot = array[right], save = 0;

	for (j = left; j < right; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				save = array[i];
				array[i] = array[j];
				array[j] = save;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[right])
	{
		save = array[i + 1];
		array[i + 1] = array[right];
		array[right] = save;
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * sort - Use the quick sort algorithm to sort an array
 * @array: The array to sort
 * @left: The first element of the array
 * @right: The last element of the array
 * @size: The size of the array
 */
void sort(int *array, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = split(array, left, right, size);
		sort(array, left, pivot - 1, size);
		sort(array, pivot + 1, right, size);
	}
}
/**
 * quick_sort - Makes a call to the sort function. See the sort function
 *		for more details
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL && size >= 2)
		sort(array, 0, size - 1, size);
}
