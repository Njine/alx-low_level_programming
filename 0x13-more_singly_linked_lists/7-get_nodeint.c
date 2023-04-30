#include "lists.h"

/**
 * Returns the node at a given index in a linked list of type listint_t.
 * @param head: Pointer to the first node of the linked list
 * @param index: Index of the node to return
 * @return: Pointer to the node at the given index, or NULL if it doesn't exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    unsigned int i;
    listint_t *temp;

    if (head == NULL)
        return (NULL);

    temp = head;
    for (i = 0; i < index && temp != NULL; i++)
        temp = temp->next;

    if (i == index)
        return (temp);

    return (NULL);
}

