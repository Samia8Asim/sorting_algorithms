#include "sort.h"

/**
 * counting_sort - function to sorts an array of int
 * @array: input array of int
 * @size: size of array
 */

void counting_sort(int *array, size_t size)
{
	int max = array[0], j;
	size_t i, idx;
	int *count;

	if (size <= 1)
		return;
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
	{
		return;
	}
	for (j = 0; j <= max; j++)
	{
		count[j] = 0;
	}
	for (i = 0; i < size; i++)
	{
		count[array[i]]++;
	}
	print_array(array, size);
	idx = 0;
	for (j = 0; j <= max; j++)
	{
		while (count[j] > 0)
		{
			array[idx++] = j;
			count[j]--;
		}
	}
	free(count);
}
