#include "lists.h"

/**
 * Adds a new node at the beginning of a linked list of type listint_t.
 * @param head: Pointer to a pointer to the first node of the linked list
 * @param n: Integer value to be stored in the new node
 * @return Pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
    listint_t *new_node = malloc(sizeof(listint_t));
    if (!new_node) {
        return NULL;
    }

    new_node->n = n;
    new_node->next = *head;
    *head = new_node;

    return new_node;
}

