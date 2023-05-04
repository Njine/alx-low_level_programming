#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - converts a binary number represented as a string to an
 * unsigned integer
 * @b: pointer to the binary string to be converted
 * Return: the converted decimal number, or 0 if there is an unconvertible
 * character
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int total = 0, power = 1;
	int len;

	/* Return 0 if the input string is NULL */
	if (b == NULL)
		return (0);

	/* Check that each character in the string is a '0' or '1' */
	for (len = 0; b[len]; len++)
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);
	}

	/* Convert the binary string to an unsigned integer */
	for (len--; len >= 0; len--, power *= 2)
	{
		if (b[len] == '1')
			total += power;
	}

	return (total);
}

