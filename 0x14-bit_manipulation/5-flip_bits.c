#include "main.h"

/**
 * flip_bits - Counts the no of bits for flipping to flip numbers.
 * @n: The 1st no.
 * @m: The 2nd no to flip to.
 * Return: The no of bits that need to be flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int bal = n ^ m;
	unsigned int count = 0;

	while (bal)
	{
		count += bal & 1;
		bal >>= 1;
	}

	return (count);
}

