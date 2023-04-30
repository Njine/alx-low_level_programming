#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given index in a linked list.
 * @head: pointer to the first node in the list.
 * @idx: index where the new node is added.
 * @n: data to insert in the new node.
 *
 * Return: pointer to the new node, or NULL.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    unsigned int i;
    listint_t *new_node;
    listint_t *temp = *head;

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL || head == NULL)
        return (NULL);

    new_node->n = n;
    new_node->next = NULL;

    if (idx == 0)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    for (i = 0; temp && i < idx - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        free(new_node);
        return (NULL);
    }

    new_node->next = temp->next;
    temp->next = new_node;

    return (new_node);
}

