#include "hash_tables.h"

/**
 * hash_table_print - short description
 *
 * Description: long description
 *
 * @ht: argument_1 description
 *
 * Return: return description
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *current_node;
	unsigned long int indexArray;
	int this_first, this_first_hash;

	if (ht == NULL)
		return;
	printf("{");
	this_first_hash = 1;
	for (indexArray = 0; indexArray < ht->size; indexArray++)
	{
		if ((ht->array)[indexArray] == NULL)
			continue;
		if (!this_first_hash)
			printf(", ");
		current_node = (ht->array)[indexArray];
		this_first = 1;
		while (current_node)
		{
			if (!this_first)
				printf(", ");
			printf("\'%s\': \'%s\'", current_node->key,
					current_node->value);
			this_first = 0;
			current_node = current_node->next;
		}
		current_node = NULL;
		this_first_hash = 0;
	}
	printf("}\n");
}
