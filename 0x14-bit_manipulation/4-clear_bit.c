#include "main.h"
#include <stdio.h>

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer to decimal number to change
 * @index: index position to change, starting from 0
 *
 * Return: 1 if it worked, -1 if error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	/* Check if index is out of range */
	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	/* Create a mask to clear the bit at the given index */
	mask = 1UL << index;

	/* Clear the bit at the given index */
	*n &= ~mask;

	return (1);
}

