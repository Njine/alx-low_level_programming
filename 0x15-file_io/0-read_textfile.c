#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
* read_textfile- Read text file print to STDOUT.
* @filename: text file being read
* @letters: number of letters to be read
* Return: b- number of bytes read and printed
*        0 when function fails or filename is NULL.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
int sf;
char *cus;
ssize_t b, t;

if (filename == NULL)
return (0);

sf = open(filename, O_RDONLY);
if (sf == -1)
return (0);

cus = malloc(sizeof(char) * letters);
if (cus == NULL)
{
close(sf);
return (0);
}

t = read(sf, cus, letters);
if (t == -1)
{
free(cus);
close(sf);
return (0);
}

b = write(STDOUT_FILENO, cus, t);
if (b == -1 || b != t)
{
free(cus);
close(sf);
return (0);
}

free(cus);
close(sf);
return (b);
}

