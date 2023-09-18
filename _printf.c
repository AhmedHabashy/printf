#include "main.h"
/**
* _printf - prints formated output to the screen
* @format: the formating type (%,c,s)
* @...: variable number of parameters representing inputs
* Return: sum success , -1 fail
*/
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ptr;

	va_start(ptr, format);
	/* check if format is null or only has an empty space */
	if (format[0] == NULL || format[0] == ' ' && format[1] == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			_putchar(*format);
			sum++;
			format++;
			continue;
		}
		/* if there is % go to the next char*/
		format++;
		/* check if format only has a % or has space/null after it*/
		if (*format == ' ' || *format == NULL)
			return (-1);
		print_handler(*format, &ptr);
		sum++;
		format++;
	}
	va_end(ptr);
	return (sum);
}
