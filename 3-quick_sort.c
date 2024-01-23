#include "sort.h"

/**
 * swap - swap the elements
 * @x: first element
 * @y: second element
 */
void swap(int *x, int *y)
{
	int tmp = *x;

	*x = *y;
	*y = tmp;
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
int lomuto(int *array, int l, int h, size_t size)
{
	int p = array[h];
	int i = l - 1, j;

	for (j = l; j < h; j++)
	{
		if (array[j] < p)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	swap(&array[i + 1], &array[h]);
	print_array(array, size);

	return (i + 1);
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
	int pivot;

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
	if (size < 2)
		return;

	quick_helper(array, 0, size - 1, size);
}
