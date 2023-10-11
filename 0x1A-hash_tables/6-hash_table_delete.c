#include "hash_tables.h"

/**
 * hash_table_delete - short description
 *
 * Description: long description
 *
 * @ht: argument_1 description
 *
 * Return: return description
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *now_node, *former_node;
	unsigned long int indexArray, with_nodes;

	for (indexArray = 0; indexArray < ht->size; indexArray++)
	{
		with_nodes = 0;
		now_node = (ht->array)[indexArray];
		while (now_node)
		{
			with_nodes = 1;
			former_node = now_node;
			now_node = now_node->next;
			free(former_node->key);
			free(former_node->value);
			free(former_node);
		}
		if (!with_nodes)
			free((ht->array)[indexArray]);
	}
	free(ht->array);
	free(ht);
}
