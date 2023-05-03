#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
* print_listint_safe - Prints a listint_t linked list.
* @head: A pointer to the head of the list.
*
* Return: The number of nodes in the list.
*/
size_t print_listint_safe(const listint_t *head)
{
const listint_t *slow, *fast;
size_t count = 0;

if (head == NULL) {
exit(98);
}

slow = head;
fast = head;

for (; slow && fast && fast->next; slow = slow->next, fast = fast->next->next) {
if (slow == fast) {
printf("-> [%p] %d\n", (void *)slow, slow->n);
break;
}
printf("[%p] %d\n", (void *)slow, slow->n);
count++;
}

if (fast && fast->next) {
count = 1;
slow = head;

for (; slow != fast; slow = slow->next, fast = fast->next) {
printf("[%p] %d\n", (void *)slow, slow->n);
count++;
}
printf("-> [%p] %d\n", (void *)slow, slow->n);
} else {
printf("[%p] %d\n", (void *)slow, slow->n);
count++;
}

return (count);
}

