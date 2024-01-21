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
 * bubble_sort - bubble_sort algorithm
 * @array: numbers array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (!array || !size)
		return;

	for (i = 0; i < size ; i++)
	{
		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
