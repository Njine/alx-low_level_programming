#include "lists.h"
#include <stdio.h>

/**
* looped_listint_len - Counts the number of unique nodes
* in a looped listint_t linked list.
* @head: A pointer to the head of the listint_t to check.
*
* Return: If the list is not looped - 0.
* Otherwise - the number of unique nodes in the list.
*/
size_t looped_listint_len(const listint_t *head)
{
const listint_t *carrot = head, *stick = head;
size_t nodes = 0;

while (stick && stick->next)
{
stick = stick->next->next;
carrot = carrot->next;

if (stick == carrot)
{
nodes++;

stick = head;
while (carrot != stick)
{
nodes++;
carrot = carrot->next;
stick = stick->next;
}

carrot = carrot->next;
while (carrot != stick)
{
nodes++;
carrot = carrot->next;
}

return (nodes);
}
}

return (0);
}


