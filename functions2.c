#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * printPointer - Prints the value of a pointer variable
 * @argsList: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int printPointer(va_list argsList, char buffer[],
	int flags, int width, int precision, int size)
{
	char extraCharacter = 0, padding = ' ';
	int index = BUFF_SIZE - 2, length = 2, paddingStart = 1; /* length=2, for '0x' */
	unsigned long address;
	char mapTo[] = "0123456789abcdef";
	void *pointerAddress = va_arg(argsList, void *);

	UNUSED(width);
	UNUSED(size);

	if (pointerAddress == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	address = (unsigned long)pointerAddress;

	while (address > 0)
	{
		buffer[index--] = mapTo[address % 16];
		address /= 16;
		length++;
	}

	if ((flags & FLAG_ZERO) && !(flags & FLAG_MINUS))
		padding = '0';
	if (flags & FLAG_PLUS)
		extraCharacter = '+', length++;
	else if (flags & FLAG_SPACE)
		extraCharacter = ' ', length++;

	index++;

	return (writePointer(buffer, index, length,
		width, flags, padding, extraCharacter, paddingStart));
}

/************************* PRINT NON-PRINTABLE *************************/
/**
 * printNonPrintable - Prints ASCII codes in hexadecimal of non-printable characters
 * @argsList: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int printNonPrintable(va_list argsList, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(argsList, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (isPrintable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += appendHexadecimalCode(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * printReverse - Prints a reverse string.
 * @argsList: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */

int printReverse(va_list argsList, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(argsList, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char character = str[i];

		write(1, &character, 1);
		count++;
	}
	return (count);
}

/************************* PRINT A STRING IN ROT13 *************************/
/**
 * printRot13String - Print a string in ROT13.
 * @argsList: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int printRot13String(va_list argsList, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(argsList, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}

