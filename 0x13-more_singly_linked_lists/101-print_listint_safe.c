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

if (head == NULL)
return -1;

slow = head;
fast = head;

while (slow && fast && fast->next)
{
slow = slow->next;
fast = fast->next->next;

if (slow == fast)
{
printf("-> [%p] %d\n", (void *)slow, slow->n);
break;
}

printf("[%p] %d\n", (void *)slow, slow->n);
count++;
}

if (fast && fast->next)
{
count = print_loop(slow, head);
}

else
{
count = print_list(slow);
}

return (count);
}

/**
* print_loop - Prints a list with a loop.
* @loop_node: A pointer to the node where the loop starts.
* @head: A pointer to the head of the list.
*
* Return: The number of nodes in the list.
*/
size_t print_loop(const listint_t *loop_node, const listint_t *head)
{
const listint_t *node;
size_t count = 1;

node = head;

while (node != loop_node)
{
printf("[%p] %d\n", (void *)node, node->n);
count++;
node = node->next;
}

printf("-> [%p] %d\n", (void *)node, node->n);

return (count);
}

/**
* print_list - Prints a list without a loop.
* @head: A pointer to the head of the list.
*
* Return: The number of nodes in the list.
*/
size_t print_list(const listint_t *head)
{
const listint_t *node = head;
size_t count = 0;

while (node)
{
printf("[%p] %d\n", (void *)node, node->n);
count++;
node = node->next;
}

return (count);
}

