#include "main.h"

void printBuffer(char buffer[], int *buffIndex);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed characters count.
 */
int _printf(const char *format, ...)
{
	int i, totalPrinted = 0, printedChars = 0;
	int flags, width, precision, size, buffIndex = 0;
	va_list argsList;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(argsList, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffIndex++] = format[i];
			if (buffIndex == BUFF_SIZE)
				printBuffer(buffer, &buffIndex);
			printedChars++;
		}
		else
		{
			printBuffer(buffer, &buffIndex);
			flags = getFlags(format, &i);
			width = getWidth(format, &i, argsList);
			precision = getPrecision(format, &i, argsList);
			size = getSize(format, &i);
			++i;
			totalPrinted = handlePrint(format, &i, argsList, buffer,
				flags, width, precision, size);
			if (totalPrinted == -1)
				return (-1);
			printedChars += totalPrinted;
		}
	}

	printBuffer(buffer, &buffIndex);

	va_end(argsList);

	return (printedChars);
}

/**
 * printBuffer - Prints the contents of the buffer if it exists
 * @buffer: Array of characters
 * @buffIndex: Index at which to add the next character, represents the length.
 */
void printBuffer(char buffer[], int *buffIndex)
{
	if (*buffIndex > 0)
		write(1, &buffer[0], *buffIndex);

	*buffIndex = 0;
}

