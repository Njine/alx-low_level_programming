#include "lists.h"

/**
 * Frees a linked list of type listint_t.
 * @param head: Pointer to the first node of the linked list
 */
void free_listint(listint_t *head)
{
    listint_t *temp;

    while (head != NULL) {
        temp = head->next;
        free(head);
        head = temp;
    }
}

