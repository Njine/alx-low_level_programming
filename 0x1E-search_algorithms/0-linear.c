#include "search_algos.h"

/**
 * linear_search - searches for value in an array of
 * integers using Linear search algorithm
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search for
 * Return: Index of the value if found, otherwise -1
 */
int linear_search(int *array, size_t size, int value)
{
	int index = 0;

	if (!array)
		return (-1);

	while (index < (int)size)
	{
		printf("Value checked array[%d] = [%d]\n", index, array[index]);
		if (value == array[index])
			return (index);
		index++;
	}

	return (-1);
}

