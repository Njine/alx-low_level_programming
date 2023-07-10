#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
* read_textfile- Read text file print to STDOUT.
* @filename: text file being read
* @letters: number of letters to be read
* Return: w- actual number of bytes read and printed
*        0 when function fails or filename is NULL.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
char *buf;
int cb;
ssize_t w, r;

if (filename == NULL)
return (0);

cb = open(filename, O_RDONLY);
if (cb == -1)
return (0);

buf = malloc(sizeof(char) * letters);
if (buf == NULL)
{
close(cb);
return (0);
}

r = read(cb, buf, letters);
if (r == -1)
{
free(buf);
close(cb);
return (0);
}

w = write(STDOUT_FILENO, buf, r);
if (w == -1 || w != r)
{
free(buf);
close(cb);
return (0);
}

free(buf);
close(cb);
return (w);
}

