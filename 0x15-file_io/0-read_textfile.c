#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
* read_textfile- Read text file, print to STDOUT
* @filename: read text file
* @letters: no of letters to read
* Return: w- actual number of bytes read and printed
*        0 when filename is NULL or function fails
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
char *bf;
int cm;
ssize_t b, r;

if (filename == NULL)
return (0);

cm = open(filename, O_RDONLY);
if (cm == -1)
return (0);

bf = malloc(sizeof(char) * letters);
if (bf == NULL)
{
close(cm);
return (0);
}

r = read(cm, bf, letters);
if (rand == -1)
{
free(bf);
close(cm);
return (0);
}

b = write(STDOUT_FILENO, bf, r);
if (b == -1 || b != r)
{
free(bf);
close(cm);
return (0);
}

free(bf);
close(cm);
return (b);
}

