#include "main.h"

/**
 * set_bit - sets value of a bit to 1 at a given index
 * @n: pointer to decimal number
 * @index: index position to change, starting from 0
 *
 * Return: 1 if it worked, -1 if error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
	return (-1);

	unsigned long int bit_value = 1UL << index;

	*n |= bit_value;

	return (1);
}

