#include <stdio.h>

void ft_putchar(char c)
{
  fwrite(&c, sizeof(c), 1, stdout);
}
