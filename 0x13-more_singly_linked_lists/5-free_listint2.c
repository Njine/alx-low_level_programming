#include "lists.h"

/**
 * free_listint2 - Frees linked list of type listint_t; sets the head to NULL
 * @head: Pointer to the first node of the linked list
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL || *head == NULL)
	return;

	while (*head != NULL)
	{
	temp = (*head)->next;
	free(*head);
	*head = temp;
	}

	*head = NULL;
}

