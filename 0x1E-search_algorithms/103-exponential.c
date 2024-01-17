#include "search_algos.h"

/**
 * exponential_search - searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 *
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: the first index where value is located, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t index, low, high, mid;

	if (array == NULL || size == 0)
		return (-1);

	if (array[0] == value)
		return (0);

	index = 1;
	while (index < size && array[index] <= value)
	{
		printf("Value checked array[%d] = [%d]\n", (int)index, array[index]);
		index *= 2;
	}

	low = index / 2;
	high = (index < size) ? index : size - 1;

	printf("Value found between indexes [%d] and [%d]\n", (int)low, (int)high);

	while (low <= high)
	{
		printf("Searching in array:");
		for (mid = low; mid <= high; mid++)
			printf("%s %d", (mid == low) ? "" : ",", array[mid]);
		printf("\n");

		mid = (low + high) / 2;
		if (array[mid] == value)
			return ((int)mid);

		(array[mid] < value) ? (low = mid + 1) : (high = mid - 1);
	}

	return (-1);
}

