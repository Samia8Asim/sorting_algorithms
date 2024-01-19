#include "sort.h"


/**
 * swap - function to swap two numbers
 * @n1: first number
 * @n2: second number
 */
void swap(int *n1, int *n2)
{
	int *temp = *a;

	*a = *b;
	*b = *temp;
}
/**
 * bubble_sort - bubble_sort algorithm
 * @array: numbers array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array)
			}
		}
	}
}
