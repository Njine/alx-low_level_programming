#include <main.h>
#include <unistd.h>

/**
 * _putchar - prints the character c to stdout
 * @c: To be printed
 *
 * Return: 1 if successful.
 * On error, -1 is returned, and errno is set
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
