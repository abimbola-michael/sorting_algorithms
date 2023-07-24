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
