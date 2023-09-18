#include "main.h"
/**
* print_string - outputs full string
* @ptr: pointer to a variadic list of arguments
* Return: num of chars printed
*/
int print_string(va_list *ptr)
{
	char *value = va_arg(*ptr, char*);

	if (value == (char *)0)
		return (_puts("(null)"));
	return (_puts(value));
}
