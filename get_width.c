#include "main.h"

/**
 * getWidth - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: Index in the format string.
 * @list: List of arguments.
 *
 * Return: Width specifier.
 */
int getWidth(const char *format, int *i, va_list list)
{
	int currentIndex;
	int width = 0;

	for (currentIndex = *i + 1; format[currentIndex] != '\0'; currentIndex++)
	{
		if (is_digit(format[currentIndex]))
		{
			width *= 10;
			width += format[currentIndex] - '0';
		}
		else if (format[currentIndex] == '*')
		{
			currentIndex++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = currentIndex - 1;

	return (width);
}

