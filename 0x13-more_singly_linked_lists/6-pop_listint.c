#include "lists.h"

/**
 * Deletes the head node of a linked list of type listint_t.
 * @param head: Pointer to the first node of the linked list
 * @return: The data inside the deleted node, or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
    listint_t *temp;
    int data;

    if (head == NULL || *head == NULL)
        return (0);

    data = (*head)->n;
    temp = (*head)->next;
    free(*head);
    *head = temp;

    return (data);
}

