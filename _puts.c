#include "main.h"
/**
* _puts - prints a string
* @str: the address of the string to be printed
* Return: printed sum
*/
int _puts(char *str)
{
	int sum = 0;

	while (*str != '\0')
	{
		sum += write(1, str, 1);
		str++;
	}
	return (sum);
}
