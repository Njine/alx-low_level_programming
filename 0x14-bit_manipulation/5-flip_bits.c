#include "main.h"

/**
 * flip_bits - Counts no of bits for flipping to flip nos.
 * @n: The 1st no.
 * @m: The 2nd no to flip to.
 * Return: The no of bits that need to be flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int rem = n ^ m;
	unsigned int count = 0;

	while (rem)
	{
		count += rem & 1;
		rem >>= 1;
	}

	return (count);
}

