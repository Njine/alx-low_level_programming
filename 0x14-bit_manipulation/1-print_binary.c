#include "main.h"
#include <stdio.h>

/**
* print_binary - print binary image of a no
* @n: decimal no to print binary
*/
void print_binary(unsigned long int n)
{
int bitnum = 0;
unsigned long int alt;

if (n == 0)
{
putchar('0');
return;
}

alt = n;
while (alt > 0)
{
bitnum++;
alt >>= 1;
}

while (bitnum > 0)
{
if ((n >> (bitnum - 1)) & 1)
putchar('1');
else
putchar('0');
bitnum--;
}
}

