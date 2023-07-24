#include "sort.h"
#include "sort.h"
/**
 * swapping_slot - used to swap values between two
 * different slots
 * @first_slot: first slot to be swapped
 * @second_slot: second slot to be swapped to
 */
void swapping_slot(int *first_slot, int *second_slot)
{
	int temp;

	temp = *first_slot;
	*first_slot = *second_slot;
	*second_slot = temp;
}

/**
 * lumoto2 - sorting of the sub array in
 * ascending order
 * @array: the pointer to the array of integer to be sorted
 * @size: size of the array
 * @first: first index of the array
 * @last: last index of the array
 * Return: the index of the sorted array
 */
int lumoto2(int *array, size_t size, int first, int last)
{
	int *temp, n1, n2;

	temp = array + last;
	for (n1 = first, n2 = first; n2 < last; n2++)
	{
		if (array[n2] < *temp)
		{
			if (n1 < n2)
			{
				swapping_slot(array + n2, array + n1);
				print_array(array, size);
			}
			n1++;
		}
	}
	if (array[n1] > *temp)
	{
		swapping_slot(array + n1, temp);
		print_array(array, size);
	}
	return (n1);
}

/**
 * lumoto1 - this uses recursion in sorting the elements
 * @array: array with the element to be sorted
 * @size: size of the array
 * @first: first index of the array
 * @last: last index of the array
 */
void lumoto1(int *array, size_t size, int first, int last)
{
	int temp;

	if (last - first > 0)
	{
		temp = lumoto2(array, size, first, last);
		lumoto1(array, size, first, last - 1);
		lumoto1(array, size, temp + 1, last);
	}
}

/**
 * quick_sort - using a quick sort to sort
 * elements in an array in ascending order
 * @array: array with the element to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lumoto1(array, size, 0, size - 1);
}
