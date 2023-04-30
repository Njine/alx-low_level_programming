#include "lists.h"

/**
 * Returns the number of elements in a linked list of type listint_t
 * @param h: Pointer to the head node of the linked list
 * @return Number of nodes in the linked list
 */
size_t listint_len(const listint_t *h)
{
    size_t num = 0;
    while (h != NULL) {
        num++;
        h = h->next;
    }
    return num;
}

