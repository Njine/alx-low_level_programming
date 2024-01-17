#include "search_algos.h"
#include <math.h>

/**
 * jump_list - searches for a value in a singly linked list
 * using the Jump search algorithm
 *
 * @list: input list
 * @size: size of the list
 * @value: value to search for
 * Return: pointer to the node containing the value, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump, prev_index;
	listint_t *current, *prev;

	if (list == NULL || size == 0)
		return (NULL);

	jump = (size_t)sqrt(size);
	current = list;

	while (current && current->n < value)
	{
		prev = current;
		prev_index = current->index;
		for (size_t i = 0; i < jump && current->next; i++)
		{
			current = current->next;
		}
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev_index, current->index);

	for (; prev && prev->index <= current->index; prev = prev->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
	}

	return (NULL);
}

