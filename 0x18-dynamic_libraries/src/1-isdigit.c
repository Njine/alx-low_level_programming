#include <stdio.h>
#include "main.h"
/**
* _isdigit - checks if a number is an intager (0 through 9)
* @c: number to check
*
* Return: 1 if c is a intager, else 0
*/
int _isdigit(int c)
{
    char digit = '0';

    while (digit <= '9')
    {
        if (c == digit)
            return (1);
        digit++;
    }

    return (0);
}
