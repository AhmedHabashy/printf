#include "main.h"
/**
* print_char - prints chars
* @ptr: pointer to va_list
*/
void print_char(va_list *ptr)
{
	char value = va_arg(*ptr, int);

	_putchar(value);
}
