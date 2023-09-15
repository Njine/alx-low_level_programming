#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all the data (n) in a dlistint_t list.
 * @head: Pointer to the head of the list.
 *
 * Return: Sum of all data values, or 0 if the list is empty.
 */
int sum_dlistint(dlistint_t *head)
{
    int add = 0;

    while (head != NULL)
    {
        add += head->n;
        head = head->next;
    }

    return (sum);
}