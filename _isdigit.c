#include "monty.h"

/**
 * _isdigit - checks for a digit
 * @c: expected function parameter
 * Return: Always 0.
 */
int _isdigit(int c)
{
if (c >= '0' && c <= '9')
{
return (1);
}
else
{
return (0);
}
}