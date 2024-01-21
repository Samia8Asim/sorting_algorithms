#include "sort.h"

/**
 * bubble_sort - bubble_sort algorithm
 * @array: numbers array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (!array || !size)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
