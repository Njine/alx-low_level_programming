#include "hash_tables.h"

/**
 * hash_table_create - function that creates a hash table
 * @size: the size of the array
 *
 * Return: return NULL or a pointer to the hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *the_table;
	unsigned long int index;

	the_table = (hash_table_t *)malloc(sizeof(hash_table_t));
	if (the_table == NULL)
		return (NULL);
	the_table->size = size;
	the_table->array = (hash_node_t **)malloc(sizeof(hash_node_t *) * size);
	if (the_table->array == NULL)
	{
		free(the_table);
		return (NULL);
	}
	for (index = 0; index < size; index++)
		the_table->array[index] = NULL;
	return (the_table);
}
