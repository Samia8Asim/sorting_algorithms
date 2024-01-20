#include "sort.h"

/**
 * swap - function to swap two numbers
 * @n1: first number
 * @n2: second number
*/
void swap(int *n1, int *n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

/**
 * selection_sort - selection sort algorithm
 * @array: input array to be sorted
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, k, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			swap(&array[i], &array[min]);
			for (k = 0; k < size; k++)
				print_array(array, size);
		}
	}

}
