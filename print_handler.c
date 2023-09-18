#include "main.h"
/**
* print_handler - maps a format to a certain function
* @format: char to determine the format
* @ptr: pointer to the list of variadic arguments
* Return: sum of printed
*/
int print_handler(char const *format, va_list *ptr)
{
	if (*format == '%')
		return (_putchar('%'));
	else if (*format == 'c')
		return (print_char(ptr));
	else if (*format == 's')
		return (print_string(ptr));
	return (0);
}
