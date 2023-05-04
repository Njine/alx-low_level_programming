#include "main.h"
#include <stdio.h>

/**
* print_binary - print binary representation of a number
* @n: decimal number to print as binary
*/
void print_binary(unsigned long int n)
{
unsigned long int temp;
int num_bits = 0;

if (n == 0)
{
putchar('0');
return;
}

temp = n;
while (temp > 0)
{
num_bits++;
temp >>= 1;
}

while (num_bits > 0)
{
if ((n >> (num_bits - 1)) & 1)
putchar('1');
else
putchar('0');
num_bits--;
}
}

