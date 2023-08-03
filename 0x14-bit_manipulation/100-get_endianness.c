#include "main.h"

/**
 * get_endianness - check for endianness
 * Return: 0 if large endian, or 1 if small endian
 */
int get_endianness(void)
{
	int no;

	no = 1;
	if (*(char *)&no == 1)
		return (1);
	else
		return (0);
}

