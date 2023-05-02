#include "lists.h"

/**
* find_listint_loop - finds the loop in a linked list
* @head: linked list to search for
*
* Return: address of the node where the loop starts, or NULL
*/
listint_t *find_listint_loop(listint_t *head)
{
listint_t *carrot = head;
listint_t *stick = head;

if (!head)
return (NULL);

while (carrot && stick && stick->next)
{
stick = stick->next->next;
carrot = carrot->next;
if (stick == carrot)
{
carrot = head;
while (carrot != stick)
{
carrot = carrot->next;
stick = stick->next;
}
return (stick);
}
}

return (NULL);
}

