#include <main.h>
#include <unistd.h>

/**
 * _putchar - prints char c to stdout
 * @c: To print
 *
 * Return: 1 if ok.
 * On error, -1 is returned, and errno is set
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
