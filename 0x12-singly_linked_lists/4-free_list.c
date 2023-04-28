#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a linked list
 * @head: pointer to the head of the list_t list to be freed
 */
void free_list(list_t *head)
{
	list_t *temp_node;

	while (head != NULL)
	{
		temp_node = head->next;
		free(head->str);
		free(head);
		head = temp_node;
	}
}

