#include "search_algos.h"

/**
 * rec_search - searches for a value in an array of
 * integers using the Binary search algorithm
 *
 * @array: input array
 * @start: starting index of the search range
 * @end: ending index of the search range
 * @value: value to search in
 * Return: index of the number, or -1 if not found
 */
int rec_search(int *array, size_t start, size_t end, int value)
{
	size_t half, i;

	if (array == NULL || start > end)
		return (-1);

	printf("Searching in array");

	for (i = start; i <= end; i++)
		printf("%s %d", (i == start) ? ":" : ",", array[i]);

	printf("\n");

	half = start + (end - start) / 2;

	if (value == array[half])
	{
		if (half > start)
			return (rec_search(array, start, half - 1, value));
		return ((int)half);
	}

	if (value < array[half])
		return (rec_search(array, start, half - 1, value));

	return (rec_search(array, half + 1, end, value));
}

/**
 * advanced_binary - calls rec_search to return
 * the index of the number
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: index of the number, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	int index;

	index = rec_search(array, 0, size - 1, value);

	if (index >= 0 && array[index] != value)
		return (-1);

	return (index);
}

