#include <stdio.h>
#include <stdlib.h>

/**
* read_textfile - Reads text file then prints to POSIX stdout
* @filename: pointer to the name of file
* @letters: number of letters the
*           function reads and prints
*
* Return: If the function fails or filename is NULL, return 0
*         O/w - the number of bytes the function can read and print
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
ssize_t r, w;
char *buffer;

if (filename == NULL)
return (0);

FILE *fp = fopen(filename, "r");
if (fp == NULL)
return (0);

buffer = malloc(sizeof(char) * letters);
if (buffer == NULL)
{
fclose(fp);
return (0);
}

r = fread(buffer, sizeof(char), letters, fp);
w = fwrite(buffer, sizeof(char), r, stdout);

if (r == 0 || w != r)
{
free(buffer);
fclose(fp);
return (0);
}

free(buffer);
fclose(fp);

return (w);
}

