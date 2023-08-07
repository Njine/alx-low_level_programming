#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
* create_file - Creates file.
* @filename: A pointer to name of file to create.
* @text_content: pointer to string to write to file.
*
* Return: If function fails - -1.
*         Otherwise - 1.
*/
int create_file(const char *filename, char *text_content)
{
int mf, c, k = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
while (text_content[k] != '\0')
k++;
}

mf = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
if (mf == -1)
return (-1);

c = write(mf, text_content, k);
if (c == -1)
{
close(mf);
return (-1);
}

close(mf);
return (1);
}

