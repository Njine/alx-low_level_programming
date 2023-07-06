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
	unsigned int total = 0;
	unsigned int power = 1;
	int lan;

	/* Return 0 if input string is NULL */
	if (b == NULL)
		return (0);
	/* Check if each character in string is a '0' or '1' */
	for (lan = 0; b[lan]; lan++)
	{
		if (b[lan] != '0' && b[lan] != '1')
			return (0);
	}
	/* Convert the binary string to an unsigned integer */
	for (lan--; lan >= 0; lan--, power *= 2)
	{
		if (b[lan] == '1')
			total += power;
	}

		return (total);
}

