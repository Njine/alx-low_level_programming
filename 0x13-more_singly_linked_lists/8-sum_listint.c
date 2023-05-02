#include "lists.h"

/**
 * sum_listint - Calculates the sum of all the data in a listint_t linked list.
 *
 * @head: Pointer to the first node in the linked list.
 *
 * Return: resulting sum of data in the linked list, or 0 if empty
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	if (head == NULL)
	return (0);

	while (head != NULL)
	{
	sum += head->n;
	head = head->next;
	}

	return (sum);
}


