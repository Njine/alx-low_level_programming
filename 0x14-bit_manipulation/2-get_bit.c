#include "main.h"
#include <stdio.h>
/**
 * get_bit - returns value of bit at a index.
 * @n: the no to search.
 * @index: the index of the bit.
 *
 * Return: value of bit at ind, or -1 if an error.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	return (-1);

	return ((n >> index) & 1);
}

