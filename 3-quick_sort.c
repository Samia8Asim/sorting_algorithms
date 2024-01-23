#include "sort.h"

/**
 * swap - swap the elements
 * @x: first element
 * @y: second element
 * @array: our array
 * @size: size of array
 */
void swap(int *array, size_t size, int *x, int *y)
{
	int tmp;

	if (*x != *y)
	{
		tmp = *x;
		*x = *y;
		*y = tmp;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto - lomuto partition scheme to sort.
 * @array: our array
 * @l: low index in array
 * @h: high index in array
 * @size: size of array
 *
 * Return: index as integer
 */
size_t lomuto(int *array, int l, int h, size_t size)
{
	int p = array[h];
	int i, j;

	for (i = j = l; j < h; j++)
	{
		if (array[j] < p)
		{
			swap(array, size, &array[i], &array[j]);
			i++;
		}
	}

	swap(array, size, &array[i], &array[h]);

	return (i);
}

/**
 * quick_helper - helper function to sort the arrey
 * @array: input array to be sorted
 * @l: input low index
 * @h: input high index
 * @size: input array's size
 * Return: nothing
 */
void quick_helper(int *array, int l, int h, size_t size)
{
	size_t pivot;

	if (l < h)
	{
		pivot = lomuto(array, l, h, size);

		quick_helper(array, l, pivot - 1, size);
		quick_helper(array, pivot + 1, h, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: the input array
 * @size: the array's size
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_helper(array, 0, size - 1, size);
}
