#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
* create_buffer - Allocates 1024 bytes for buffer
* @file: name of file buffer that is storing chars for
*
* Return: pointer to the newly allocated buffer
*/
char *create_buffer(char *file)
{
char *bf;

bf = malloc(sizeof(char) * 1024);

if (bf == NULL)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", file);
exit(99);
}

return (bf);
}

/**
* close_file - Closes file descriptors.
* @fd: The file descriptor to be closed.
*/
void close_file(int fd)
{
int c;

c = close(fd);

if (c == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
* main - Copies the content of file to another file.
* @argc: number of arguments supplied to program
* @argv: array of pointers to arguments
*
* Return: 0 on success
*
* Description: If argument count is wrong - exit code 97.
* If file_from does not exist or can't be read - exit code 98.
* If file_to cannot be created or appended - exit code 99.
* If file_to or file_from can't be closed - exit code 100.
*/
int main(int argc, char *argv[])
{
int get, go, t, w;
char *bf;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

bf = create_buffer(argv[2]);
get = open(argv[1], O_RDONLY);

if (get == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", argv[1]);
free(bf);
exit(98);
}

go = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

if (go == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", argv[2]);
free(bf);
close_file(get);
exit(99);
}

do {
t = read(get, bf, 1024);

if (t == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", argv[1]);
free(bf);
close_file(get);
close_file(go);
exit(98);
}

w = write(go, bf, t);

if (w == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", argv[2]);
free(bf);
close_file(get);
close_file(go);
exit(99);
}

} while (t > 0);

free(bf);
close_file(get);
close_file(go);

return (0);
}

