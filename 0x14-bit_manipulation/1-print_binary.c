#include "main.h"
#include <stdio.h>

/**
* print_binary - print binary image of no
* @n: decimal no to print as binary
*/
void print_binary(unsigned long int n)
{
unsigned long int var;
int numbit = 0;

if (n == 0)
{
putchar('0');
return;
}

var = n;
while (var > 0)
{
numbit++;
var >>= 1;
}

while (numbit > 0)
{
if ((n >> (numbit - 1)) & 1)
putchar('1');
else
putchar('0');
numbit--;
}
}

