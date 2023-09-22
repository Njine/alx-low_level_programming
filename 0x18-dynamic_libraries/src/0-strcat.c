#include "main.h"
#include <string.h>
/**
* _strcat - Concatenates 2 strings.
* @dest: Pointer to target string.
* @src: Pointer to original string.
* Return: Pointer to the next string @dest.
*/
char *_strcat(char *dest, char *src)
{
	strcat(dest, src);
	return (dest);
}
