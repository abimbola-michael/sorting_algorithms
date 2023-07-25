#include "sort.h"

void swap(int *array, int i, int j);

/**
 * swap - function to swap valuues of ana array
 * @array: input array
 * @i: first input
 * @j: second input
 */

void swap(int *array, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
	
void merge(int *array, size_t left, size_t right, size_t size);

/**
 * merge - a function to sort an array
 * @array: array to sort
 * @left: left index
 * @right: right index
 *
 */

void merge(int *array, size_t left, size_t right, size_t size)
{
	size_t middle, i, j, k;

	if (left >= right)
		return;
	middle = (left + right) / 2;
	merge(array, left, middle, size);
	merge(array, middle + 1, right, size);

	for (i = left, j = middle + 1, k = left; i <= middle && j <= right; k++)
	{
		if (array[i] <= array[j])
		{
			array[k] = array[i];
			i++;
		}
		else
		{
			array[k] = array[j];
			j++;
		}
	}
	for (; i <= middle; i++, k++)
	{
		 array[k] = array[i];
	}
	for (; j <= right; j++, k++)
	{
		 array[k] = array[j];
	}
	print_array(array, size);
}

/**
 * merge_sort - a function that sorts an array of integers in ascending
 * order using the Merge sort algorithm
 * @array: input array
 * @size: array size
 */

void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	merge(array, 0, size - 1, size);
}
