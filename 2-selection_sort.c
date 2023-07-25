#include "sort.h"
/**
 * selection_sort - Sort an array using the selection sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	int save = 0;
	size_t i, j, pos;

	for (i = 0; i < size - 1; i++)
	{
		pos = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[pos] > array[j])
				pos = j;
		}
		if (pos != i)
		{
			save = array[i];
			array[i] = array[pos];
			array[pos] = save;
			print_array(array, size);
		}
	}
}
