#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: pointer to decimal number to change
 * @index: index position to change
 *
 * Return: 1 if it worked, -1 if error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
    if (index > 63)
	return (-1);

	*n |= 1UL << index;
	
	return (1);
}


