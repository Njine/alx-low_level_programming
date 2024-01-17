#include "search_algos.h"

/**
 * exponential_search - searches for a value in an array of
 * integers using the Exponential search algorithm
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search for
 * Return: index of the number or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t index = 1, next;

	if (array == NULL || size == 0)
		return (-1);

	while (index < size && array[index] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", index, array[index]);
		index *= 2;
	}

	next = (index >= size) ? (size - 1) : index;

	printf("Value found between indexes [%lu] and [%lu]\n",
	       index / 2, next);

	return (binary_search(array + index / 2, (next + 1) - index / 2, value) +
		(index / 2));
}

