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
	char c;

	va_start(ptr, format);
	if (!format || format[0] == '\0')
		return (0);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			sum += _putchar(*format);
			format++;
			continue;
		}
		if (*(format++) == ' ' || *(format++) == '\0')
			return (0);
		 c = *(format + 1);
		if (*format == '%' && (c != 'c' || c != 's' || c != '%'))
		{
			sum += _putchar(*format);
			format++;
			continue;
		}
		format++;
		sum += print_handler(format, &ptr);
		format++;
	}
	va_end(ptr);
	return (sum);
}
