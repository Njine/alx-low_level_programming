#include "main.h"
#include <fcntl.h>
#include <unistd.h>

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
ssize_t rd; 
ssize_t wr; 

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


rd = read(fd, buf, letters);
if (rd == -1)
{
free(buf);
close(fd);
return (0);
}


wr = write(STDOUT_FILENO, buf, rd);
if (wr == -1 || wr != rd)
{
free(buf);
close(fd);
return (0);
}


free(buf);
close(fd);

return (wr);
}

