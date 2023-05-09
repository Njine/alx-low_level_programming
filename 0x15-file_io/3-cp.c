#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
* create_buffer - Allocates BUFFER_SIZE bytes for a buffer.
* @file: The name of the file buffer is storing chars for.
*
* Return: A pointer to the newly-allocated buffer.
*/
char *create_buffer(char *file)
{
char *buffer;

buffer = malloc(sizeof(char) * BUFFER_SIZE);

if (buffer == NULL)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", file);
exit(99);
}

return (buffer);
}

/**
* close_file - Closes file descriptors.
* @fd: The file descriptor to be closed.
*/
void close_file(int fd)
{
if (close(fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
* read_file - Reads data from a file into a buffer.
* @from: The file descriptor of the source file.
* @buffer: The buffer to store the read data.
* @file: The name of the file being read.
*
* Return: The number of bytes read, or -1 on failure.
*/
int read_file(int from, char *buffer, char *file)
{
int r;

r = read(from, buffer, BUFFER_SIZE);
if (r == -1)
{
dprintf(STDERR_FILENO,

