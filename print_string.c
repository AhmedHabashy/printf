#include "main.h"
/**
* print_string - outputs full string
* @ptr: pointer to a variadic list of arguments
*/
void print_string(va_list *ptr)
{
	char *value = va_arg(*ptr, char*);

	_puts(value);
}

