#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 *
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **head)
{
	/* Declare 3 pointers to keep track of current, previous and next nodes */
	listint_t *prev = NULL;
	listint_t *current = *head;
	listint_t *next = NULL;

	/* Traverse the list and reverse the pointers */
	while (current)
	{
		next = current->next; /* Store the next node in the sequence */
		current->next = prev; /* Point the current node to the previous node */
		prev = current; /* Update the previous node to be the current node */
		current = next; /* Update current node to be the next node in sequence */
	}

	/* Update the head to point to the new first node in the list */
	*head = prev;

	return (*head);
}

