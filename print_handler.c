#include "main.h"
/**
* print_handler - maps a format to a certain function
* @format: char to determine the format
* @ptr: pointer to the list of variadic arguments
*/
void print_handler(char format, va_list *ptr)
{
	if (format == '%')
		_putchar('%');
	else if (format == 'c')
		print_char(ptr);
	else if (format == 's')
		print_string(ptr);
}
