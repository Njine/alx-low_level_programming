#include "hash_tables.h"

/**
 * hash_table_set - description
 *
 * Description: long description
 *
 * @ht: hash table
 * @key: key
 * @value: value
 *
 * Return: return description
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	hash_node_t *latest_node = NULL, *legacy_head = NULL;

	if (key == NULL || value == NULL || ht == NULL)
		return (0);
	if (strlen(key) == 0)
		return (0);
	latest_node = (hash_node_t *) malloc(sizeof(hash_node_t));
	if (latest_node == NULL)
		return (0);
	index = key_index((const unsigned char *) key, ht->size);
	latest_node->key = (char *) strdup(key);
	latest_node->value = (char *) strdup(value);
	latest_node->next = NULL;
	if ((ht->array)[index] == NULL)
	{
		(ht->array)[index] = latest_node;
		return (1);
	}
	else
	{
		legacy_head = (ht->array)[index];
		while (legacy_head)
		{
			if (strcmp(legacy_head->key, key) == 0)
			{
				free(legacy_head->value);
				legacy_head->value = (char *) strdup(value);
				free(latest_node->key);
				free(latest_node->value);
				free(latest_node);
				return (1);
			}
			legacy_head = legacy_head->next;
		}
		legacy_head = (ht->array)[index];
		latest_node->next = legacy_head;
		(ht->array)[index] = latest_node;
		return (1);
	}
}
