#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
* create_file - Creates a file.
* @filename: A pointer to the name of the file to create.
* @text_content: A pointer to a string to write to the file.
*
* Return: If the function fails - -1.
*         Otherwise - 1.
*/
int create_file(const char *filename, char *text_content)
{
int cm, b, l = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
while (text_content[l] != '\0')
l++;
}

cm = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
if (cm == -1)
return (-1);

b = write(cm, text_content, l);
if (b == -1)
{
close(cm);
return (-1);
}

close(cm);
return (1);
}

