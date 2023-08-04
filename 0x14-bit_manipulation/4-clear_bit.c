#include "main.h"
#include <stdio.h>

/**
 * clear_bit - sets value of bit to 0 at given index
 * @n: pointer to decimal no to be altered
 * @index: from 0 index position changes
 *
 * Return: 1 if correct, -1 if wrong
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int bri;

	/* index is out of range? */
	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	/* mask created to clear bit at index */
	bri = 1UL << index;

	/* Clear  bit at the index */
	*n &= ~bri;

	return (1);
}

