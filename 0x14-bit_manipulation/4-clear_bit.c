#include "main.h"
#include <stdio.h>

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer to decimal no to change
 * @index: index position changes from 0
 *
 * Return: 1 if successful, -1 if wrong
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int twit;

	/* Check if index is out of range */
	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	/* Create a mask to clear bit at index */
	twit = 1UL << index;

	/* Clear  bit at the index */
	*n &= ~twit;

	return (1);
}

