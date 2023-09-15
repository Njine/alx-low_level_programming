#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: double pointer to the head of the doubly linked list
 * @n: integer value to be stored in the new node
 * Return: the address of the new element, or NULL if it fails
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new_node, *tmp;

    if (head == NULL)
        return (NULL);

    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->next = NULL;

    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        return (new_node);
    }

    tmp = *head;
    while (tmp->next != NULL)
        tmp = tmp->next;

    new_node->prev = tmp;
    tmp->next = new_node;

    return (new_node);
}