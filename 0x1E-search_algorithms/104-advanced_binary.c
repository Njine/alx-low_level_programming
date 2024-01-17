#include "search_algos.h"

/**
 * rec_search - searches for a value in a sorted array of integers
 * using the Binary search algorithm
 *
 * @array: input array
 * @start: starting index of the array
 * @end: ending index of the array
 * @value: value to search in
 * Return: index of the number
 */
int rec_search(int *array, size_t start, size_t end, int value)
{
	size_t mid;

	if (start > end)
		return (-1);

	printf("Searching in array:");
	for (mid = start; mid <= end; mid++)
		printf("%s %d", (mid == start) ? "" : ",", array[mid]);
	printf("\n");

	mid = start + (end - start) / 2;

	if (array[mid] == value)
	{
		if (mid > 0 && array[mid - 1] == value)
			return (rec_search(array, start, mid, value));
		return ((int)mid);
	}

	if (array[mid] > value)
		return (rec_search(array, start, mid - 1, value));

	return (rec_search(array, mid + 1, end, value));
}

/**
 * advanced_binary - searches for a value in a sorted array of integers
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: index of the number
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (rec_search(array, 0, size - 1, value));
}

