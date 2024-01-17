#include "search_algos.h"

/**
 * binary_search - Search for a value in a sorted array using
 * the Binary Search algorithm
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the value if found, otherwise -1
 */
int binary_search(int *array, size_t size, int value)
{
	size_t low = 0, high = size - 1, mid;

	if (!array)
		return (-1);

	while (low <= high)
	{
		mid = (low + high) / 2;

		printf("Searching in array: ");
		for (size_t i = low; i <= high; i++)
			printf("%d%s", array[i], i == high ? "\n" : ", ");

		if (array[mid] == value)
			return (mid);
		else if (array[mid] > value)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return (-1);
}

