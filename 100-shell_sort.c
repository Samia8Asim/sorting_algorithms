#include "sort.h"

/**
 * shell_sort - function to sorts an array of int
 * @array: input array of int
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, g;

	for (g = 1; g <= size / 3; g = g * 3 + 1)
		;

	while (g > 0)
	{
		for (i = g; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= g && array[j - g] > temp; j -= g)
			{
				array[j] = array[j - g];
			}

			array[j] = temp;
		}

		print_array(array, size);
		g = (g - 1) / 3;
	}
}
