#include "main.h"

/**
 * getSize - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: Index in the format string.
 *
 * Return: Size specifier.
 */
int getSize(const char *format, int *i)
{
	int currentIndex = *i + 1;
	int size = 0;

	if (format[currentIndex] == 'l')
		size = S_LONG;
	else if (format[currentIndex] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = currentIndex - 1;
	else
		*i = currentIndex;

	return (size);
}

