#include "sort.h"
#include <stdio.h>
/**
 * bubble_sort - Sort a array using the bubble sort algorithm
 * @array: The array to sort
 * @size: The array size
 */
void bubble_sort(int *array, size_t size)
{
	int temp = 0;
	size_t i = 0, n = size, save;

	if (array != NULL && size != 0)
	{
		while (n > 1)
		{
			save = 0;
			for (i = 1; i < n; i++)
			{
				if (array[i - 1] > array[i])
				{
					save = i;
					temp = array[i - 1];
					array[i - 1] = array[i];
					array[i] = temp;
					print_array(array, size);
				}
			}
			n = save;
		}
	}
}
