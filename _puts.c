#include "main.h"
/**
 * _puts - prints a string
 * @str: the address of the string to be printed
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}
