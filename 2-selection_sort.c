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
 * selection_sort - used to sort an array by selecting the first
 * element in array and comparing with all other element in array
 * @array: the list of arrays  of integers
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	int *new;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		new = array + i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *new)
				new = array + j;
			else
				new = new;
		}

		if ((array + i) != new)
		{
			swapping_slot((array + i), new);
			print_array(array, size);
		}
	}
}
