#include "sort.h"

/**
 * counting_sort - function to sorts an array of int
 * @array: input array of int
 * @size: size of array
 */

void counting_sort(int *array, size_t size)
{
	int max = 0;
	size_t i, j, k;
	int *counting;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	k = max + 1;
	counting = (int *) malloc(k * sizeof(int));
	if (counting == NULL)
		return;
	for (i = 0; i < k; i++)
	{
		counting[i] = 0;
	}
	for (i = 0; i < size; i++)
	{
		counting[array[i]]++;
	}
	for (i = 0; i < k; i++)
	{
		printf("%d ", counting[i]);
	}
	printf("\n");
	i = 0;
	for (j = 0; j < k; j++)
	{
		while (counting[j]-- > 0)
		{
			array[i++] = j;
		}
	}
	free(counting);
}
