#include "search_algos.h"
#include <math.h>

/**
 * jump_list - searches for a value in a sorted list of integers
 * using the Jump search algorithm
 *
 * @list: pointer to the head of the list to search in
 * @size: number of nodes in the list
 * @value: value to search for
 * Return: pointer to the first node where value is located, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
    size_t jump, prev_idx, curr_idx;
    listint_t *prev, *current;

    if (list == NULL || size == 0)
        return (NULL);

    jump = sqrt(size);
    prev = NULL;
    current = list;

    while (current != NULL && current->n < value)
    {
        prev = current;
        prev_idx = current->index;
        for (size_t i = 0; i < jump && current->next != NULL; i++)
        {
            current = current->next;
        }
    }

    printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);

    printf("Value found between indexes [%lu] and [%lu]\n", prev_idx, current->index);

    for (curr_idx = prev_idx; curr_idx <= current->index && current != NULL; curr_idx++)
    {
        printf("Value checked at index [%lu] = [%d]\n", curr_idx, current->n);
        if (current->n == value)
            return (current);
        current = current->next;
    }

    return (NULL);
}

