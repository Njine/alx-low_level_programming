#include "search_algos.h"

/**
 * linear_skip - searches for a value in a skip list
 *
 * @list: input list
 * @value: value to search for
 * Return: pointer to the node containing the value, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *current, *next_express;

    if (list == NULL)
        return (NULL);

    current = list;

    while (current)
    {
        next_express = current->express;

        printf("Value checked at index [%d] = [%d]\n", (next_express != NULL) ? next_express->index : current->index,
               (next_express != NULL) ? next_express->n : current->n);

        if (next_express == NULL || next_express->n >= value)
        {
            printf("Value found between indexes [%d] and [%d]\n", current->index,
                   (next_express != NULL) ? next_express->index : -1);

            while (current)
            {
                printf("Value checked at index [%d] = [%d]\n", current->index, current->n);

                if (current->n == value)
                    return (current);

                current = current->next;
            }
        }

        current = next_express;
    }

    return (NULL);
}

