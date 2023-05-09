#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
* read_textfile - Reads a text file and prints it to the POSIX standard output.
* @filename: The name of the file to be read.
* @letters: The maximum number of letters to be read and printed.
*
* Return: The actual number of letters that were read and printed.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
char *buf;
ssize_t rd, wr, total = 0;

if (filename == NULL)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

buf = malloc(sizeof(char) * (letters + 1));
if (buf == NULL)
{
close(fd);
return (0);
}

while ((rd = read(fd, buf, letters)) > 0)
{
wr = write(STDOUT_FILENO, buf, rd);
if (wr == -1)
{
free(buf);
close(fd);
return (0);
}
total += wr;
}

free(buf);
close(fd);

if (rd == -1)
return (0);

return (total);
}

