#include "main.h"

/**
 * handlePrint - Prints an argument based on its type
 * @format: Formatted string in which to print the arguments.
 * @index: Current index in the format string.
 * @list: List of arguments to be printed.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Number of characters printed or -1 on error.
 */
int handlePrint(const char *format, int *index, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknownLength = 0, printedChars = -1;
	fmt_t fmtTypes[] = {
		{'c', printChar}, {'s', printString}, {'%', printPercent},
		{'i', printInt}, {'d', printInt}, {'b', printBinary},
		{'u', printUnsigned}, {'o', printOctal}, {'x', printHexadecimal},
		{'X', printHexaUpper}, {'p', printPointer}, {'S', printNonPrintable},
		{'r', printReverse}, {'R', printRot13String}, {'\0', NULL}
	};
	for (i = 0; fmtTypes[i].fmt != '\0'; i++)
		if (format[*index] == fmtTypes[i].fmt)
			return fmtTypes[i].fn(list, buffer, flags, width, precision, size);

	if (fmtTypes[i].fmt == '\0')
	{
		if (format[*index] == '\0')
			return -1;
		unknownLength += write(1, "%%", 1);
		if (format[*index - 1] == ' ')
			unknownLength += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (format[*index] != ' ' && format[*index] != '%')
				--(*index);
			if (format[*index] == ' ')
				--(*index);
			return 1;
		}
		unknownLength += write(1, &format[*index], 1);
		return unknownLength;
	}
	return printedChars;
}

