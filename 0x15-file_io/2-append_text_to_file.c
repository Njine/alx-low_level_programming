#include "main.h"

/**
* append_text_to_file - Appends text at the end of a file.
* @filename: A pointer to the name of the file.
* @text_content: The string to add to the end of the file.
*
* Return: If the function fails or filename is NULL - -1.
*         If the file does not exist the user lacks write permissions - -1.
*         Otherwise - 1.
*/
int append_text_to_file(const char *filename, char *text_content)
{
int n, c, k = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
for (k = 0; text_content[k];)
k++;
}

n = open(filename, O_WRONLY | O_APPEND);
c = write(n, text_content, k);

if (n == -1 || c == -1)
return (-1);

close(n);

return (1);
}
