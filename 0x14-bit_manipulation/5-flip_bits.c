#include "main.h"

/**
 * flip_bits - Counts the number of bits needed to flip to convert one number to another number.
 * @n: The first number.
 * @m: The second number to convert to.
 * Return: The number of bits that need to be flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff = n ^ m;
	unsigned int counter = 0;

	while (diff)
	{
		counter += diff & 1;
		diff >>= 1;
	}

	return (counter);
}

