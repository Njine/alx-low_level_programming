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
char *cus;

cus = malloc(sizeof(char) * 1024);

if (cus == NULL)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", file);
exit(99);
}

return (cus);
}

/**
* close_file - Closes file descriptors.
* @fd: The file descriptor to be closed.
*/
void close_file(int fd)
{
int s;

s = close(fd);

if (s == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
* main - Copies content of file to another file.
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
int find, prog, u, w;
char *cus;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

cus = create_buffer(argv[2]);
find = open(argv[1], O_RDONLY);

if (find == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", argv[1]);
free(cus);
exit(98);
}

prog = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

if (prog == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", argv[2]);
free(cus);
close_file(find);
exit(99);
}

do {
u = read(find, cus, 1024);

if (u == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", argv[1]);
free(cus);
close_file(find);
close_file(prog);
exit(98);
}

w = write(prog, cus, u);

if (w == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", argv[2]);
free(cus);
close_file(find);
close_file(prog);
exit(99);
}

} while (u > 0);

free(cus);
close_file(find);
close_file(prog);

return (0);
}

