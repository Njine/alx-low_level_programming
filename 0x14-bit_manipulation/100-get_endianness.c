#include "main.h"

/**
 * get_endianness - endianness check
 * Return: 1 if small endian or 0 if large endian
 */
int get_endianness(void)
{
	int dig;

	dig = 1;
	if (*(char *)&dig == 1)
		return (1);
	else
		return (0);
}

