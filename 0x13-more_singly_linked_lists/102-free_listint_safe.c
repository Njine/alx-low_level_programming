#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list safely
 * @h: Double pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *temp;

	if (!h || !(*h))
		return (0);

	current = *h;
	while (current)
	{
		count++;
		if (current < current->next)
		{
			temp = current->next;
			free(current);
			current = temp;
		}
		else
		{
			free(current);
			*h = NULL;
			break;
		}
	}

	return (count);
}

