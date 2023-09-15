#include "lists.h"
/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: A double pointer to the head of the list.
 * @idx: The index at which the node will be added.
 * @n: The integer data to be added.
 *
 * Return: Address of the new node if successful, NULL if failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *node = malloc(sizeof(dlistint_t));
    dlistint_t *temp;
    unsigned int count = 0;

    if (node == NULL)
        return (NULL);
    node->n = n;
    node->prev = NULL;
    node->next = NULL;

    if (*h == NULL)
    {
        *h = node;
        return (node);
    }
    temp = *h;
    if (idx == 0)
    {
        node->next = temp;
        temp->prev = node;
        *h = node;
        return (node);
    }

    while (count != (idx - 1))
    {
        temp = temp->next;
        count++;
        if (temp == NULL)
        {
            free(node);
            return (NULL);
        }
    }
    node->next = temp->next;
    node->prev = temp;
    if (temp->next == NULL)
        temp->next = node;
    else
    {
        temp->next->prev = node;
        temp->next = node;
    }
    return (node);
}