#include "lists.h"

/**
 * print_listint_safe - prints a linked list safely
 * @head: pointer to the first node in the linked list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow, *fast;
	size_t count = 0;

	slow = fast = head;

	while (fast && fast->next)
	{
		count++;
		printf("[%p] %d\n", (void *)slow, slow->n);
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			printf("[%p] %d\n", (void *)slow, slow->n);
			count++;
			break;
		}
	}

	if (!fast)
	{
		while (slow)
		{
			count++;
			printf("[%p] %d\n", (void *)slow, slow->n);
			slow = slow->next;
		}
	}

	return (count);
}

