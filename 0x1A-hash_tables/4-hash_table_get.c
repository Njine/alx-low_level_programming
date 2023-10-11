#include "hash_tables.h"

/**
* hash_table_get - short description
*
* Description: long description
*
* @ht: argument_1 description
* @key: argument_2 description
*
* Return: return description
*/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
unsigned long int index;
hash_node_t *now_node;

if (ht == NULL || key == NULL)
return (NULL);
index = key_index((const unsigned char *)key, ht->size);
if ((ht->array)[index] == NULL)
return (NULL);
now_node = (ht->array)[index];
for (; now_node; now_node = now_node->next)
{
if (strcmp(now_node->key, key) == 0)
return (now_node->value);
}
return (NULL);
}
