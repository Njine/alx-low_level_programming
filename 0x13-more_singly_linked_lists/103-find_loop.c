#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to search
 *
 * Return: address of the node where the loop begins, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *slow, *fast;

    if (!head)
        return NULL;

    slow = head;
    fast = head->next;

    while (fast && fast->next && slow != fast)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (!fast || !fast->next)
        return NULL;

    slow = head;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return fast;
}

