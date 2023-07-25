#include "sort.h"

void merge(int *array, size_t left, size_t right);

/**
 * merge - a function to sort an array
 * @array: array to sort
 * @left: left index
 * @right: right index
 *
 */

void merge(int *array, size_t left, size_t right)
{
	size_t middle, i, j, k;
	size_t left_size, right_size;
	int *left_array, *right_array;

	if (left >= right)
		return;
	middle = (left + right) / 2;
	left_size = middle - left + 1;
	right_size = right - middle;
	merge(array, left, middle);
	merge(array, middle + 1, right);

	left_array = malloc(sizeof(int) * left_size);
	right_array = malloc(sizeof(int) * right_size);
	if (left_array == NULL || right_array == NULL)
		return;
	for (i = 0; i < left_size; i++)
		left_array[i] = array[left + i];
	for (j = 0; j < right_size; j++)
		right_array[j] = array[middle + j + 1];
	for (i = 0, j = 0, k = left; i < left_size && j < right_size; k++)
	{
		if (left_array[i] <= right_array[j])
		{
			array[k] = left_array[i];
			i++;
		}
		else
		{
			array[k] = right_array[j];
			j++;
		}
	}
	for (; i < left_size; i++, k++)
	{
		array[k] = left_array[i];
	}
	for (; j < right_size; j++, k++)
	{
		array[k] = right_array[j];
	}
	free(left_array);
	free(right_array);
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
	merge(array, 0, size - 1);
}
