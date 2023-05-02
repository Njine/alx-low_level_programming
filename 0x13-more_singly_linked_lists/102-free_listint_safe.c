#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the first node in the linked list
 *
 * Return: number of elements in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	size_t diff;
	listint_t *current;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		diff = (size_t)(*h) - (size_t)(*h)->next;
		if (diff > 0)
		{
			current = (*h)->next;
			free(*h);
			*h = current;
			len++;
		}
		else
		{
			free(*h);
			*h = NULL;
			len++;
			while (*h)
			{
				current = (*h)->next;
				free(*h);
				*h = current;
				len++;
			}
			break;
		}
	}

	return (len);
}

