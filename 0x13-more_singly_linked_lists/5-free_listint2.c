#include "lists.h"

/**
 * Frees a linked list of type listint_t and sets the head to NULL.
 * @param head: Pointer to the first node of the linked list
 */
void free_listint2(listint_t **head)
{
    listint_t *temp;

    if (head == NULL || *head == NULL)
        return;

    while (*head != NULL) {
        temp = (*head)->next;
        free(*head);
        *head = temp;
    }

    *head = NULL;
}

