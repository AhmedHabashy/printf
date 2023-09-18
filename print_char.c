#include "main.h"
/**
* print_char - prints chars
* @ptr: pointer to va_list
* Return: printed sum
*/
int print_char(va_list *ptr)
{
	char value = va_arg(*ptr, int);

	if (value == '\0')
		return (0);
	return (_putchar(value));
}
