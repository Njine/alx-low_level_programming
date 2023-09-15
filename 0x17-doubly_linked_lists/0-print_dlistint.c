#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - prints all elements of a dlistint_t list
 * @h: head of the doubly linked list
 * Return: the number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h)
{
    const dlistint_t *current = h;
    size_t count = 0;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
        count++;
    }

    return count;
}