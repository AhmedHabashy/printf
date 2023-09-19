#include "main.h"

/**
 * getPrecision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: Index in the format string.
 * @list: List of arguments.
 *
 * Return: Precision.
 */
int getPrecision(const char *format, int *i, va_list list)
{
	int currentIndex = *i + 1;
	int precision = -1;

	if (format[currentIndex] != '.')
		return (precision);

	precision = 0;

	for (currentIndex += 1; format[currentIndex] != '\0'; currentIndex++)
	{
		if (is_digit(format[currentIndex]))
		{
			precision *= 10;
			precision += format[currentIndex] - '0';
		}
		else if (format[currentIndex] == '*')
		{
			currentIndex++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = currentIndex - 1;

	return (precision);
}

