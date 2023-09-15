#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given index.
 * @head: Double pointer to the head of the list.
 * @index: Index of the node to delete, starting from 0.
 *
 * Return: 1 if successful, -1 if failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current = *head;

    if (*head == NULL)
        return (-1);

    if (index == 0)
    {
        *head = current->next;
        if (*head)
            (*head)->prev = NULL;
        free(current);
        return (1);
    }

    for (unsigned int i = 0; current && i < index; i++)
        current = current->next;

    if (!current)
        return (-1);

    current->prev->next = current->next;
    if (current->next)
        current->next->prev = current->prev;
    free(current);
    return (1);
}