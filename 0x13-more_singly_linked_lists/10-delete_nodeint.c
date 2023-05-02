#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes a node in a listint_t linked list at a
 *                           specified index.
 *
 * @head: Pointer to a pointer to the first node of the list.
 * @index: The index of the node to be deleted.
 *
 * Return: 1 if the operation succeeded, or -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *current;
	unsigned int i;

	if (*head == NULL)
	return (-1);

	if (index == 0)
	{
	temp = *head;
	*head = (*head)->next;
	free(temp);
	return (1);
	}

	temp = *head;

	for (i = 0; i < index - 1; i++)
	{
	if (!temp || !(temp->next))
	return (-1);
	temp = temp->next;
	}

	current = temp->next;
	temp->next = current->next;
	free(current);

	return (1);
}

