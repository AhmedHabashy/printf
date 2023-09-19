#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handleWriteChar - Prints a character
 * @c: Character to be printed.
 * @buffer: Buffer array to handle print.
 * @flags:  Calculates active flags.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int handleWriteChar(char c, char buffer[],
	int flags, int width, int precision, int size)
{ /* Character is stored at left and padding at buffer's right */
	int i = 0;
	char padding = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padding = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padding;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * writeNumber - Prints a number
 * @isNegative: Flag indicating if the number is negative.
 * @index: Index at which the number starts in the buffer.
 * @buffer: Buffer array to handle print.
 * @flags:  Calculates active flags.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int writeNumber(int isNegative, int index, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1;
	char padding = ' ', extraChar = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (isNegative)
		extraChar = '-';
	else if (flags & F_PLUS)
		extraChar = '+';
	else if (flags & F_SPACE)
		extraChar = ' ';

	return (writeNum(index, buffer, flags, width, precision,
		length, padding, extraChar));
}

/**
 * writeNum - Write a number using a buffer
 * @index: Index at which the number starts in the buffer.
 * @buffer: Buffer.
 * @flags: Flags.
 * @width: Width.
 * @precision: Precision.
 * @length: Number length.
 * @padding: Padding character.
 * @extraChar: Extra character.
 *
 * Return: Number of characters printed.
 */
int writeNum(int index, char buffer[],
	int flags, int width, int precision,
	int length, char padding, char extraChar)
{
	int i, paddingStart = 1;

	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no characters are printed */
	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = padding = ' '; /* width is displayed with padding ' ' */
	if (precision > 0 && precision < length)
		padding = ' ';
	while (precision > length)
		buffer[--index] = '0', length++;
	if (extraChar != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padding;
		buffer[i] = '\0';
		if (flags & F_MINUS && padding == ' ')/* Asign extra character to left of buffer */
		{
			if (extraChar)
				buffer[--index] = extraChar;
			return (write(1, &buffer[index], length) + write(1, &buffer[1], i - 1));
		}
		else /* Asign extra character to left of padding */
		{
			if (extraChar)
				buffer[--index] = extraChar;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], length));
		}
	}
	if (extraChar)
		buffer[--index] = extraChar;
	return (write(1, &buffer[index], length));
}

/**
 * writeUnsigned - Writes an unsigned number
 * @isNegative: Flag indicating if the number is negative.
 * @index: Index at which the number starts in the buffer.
 * @buffer: Buffer array to handle print.
 * @flags: Flags specifiers.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Number of characters written.
 */
int writeUnsigned(int isNegative, int index,
	char buffer[], int flags, int width, int precision, int size)
{
	/* The number is stored at the buffer's right and starts at position i */
	int length = BUFF_SIZE - index - 1, i = 0;
	char padding = ' ';

	UNUSED(isNegative);
	UNUSED(size);

	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		return (0); /* printf(".0d", 0)  no characters are printed */

	if (precision > 0 && precision < length)
		padding = ' ';

	while (precision > length)
	{
		buffer[--index] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padding;

		buffer[i] = '\0';

		if (flags & F_MINUS) /* Asign extra character to left of buffer [buffer > padding]*/
		{
			return (write(1, &buffer[index], length) + write(1, &buffer[0], i));
		}
		else /* Asign extra character to left of padding [padding > buffer]*/
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[index], length));
		}
	}

	return (write(1, &buffer[index], length));
}

/**
 * writePointer - Write a memory address
 * @buffer: Array of characters
 * @index: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flags: Flags specifier
 * @padding: Char representing the padding
 * @extraChar: Char representing extra character
 * @paddingStart: Index at which padding should start
 *
 * Return: Number of characters written.
 */
int writePointer(char buffer[], int index, int length,
	int width, int flags, char padding, char extraChar, int paddingStart)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padding;
		buffer[i] = '\0';
		if (flags & F_MINUS && padding == ' ')/* Asign extra character to left of buffer */
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extraChar)
				buffer[--index] = extraChar;
			return (write(1, &buffer[index], length) + write(1, &buffer[3], i - 3));
		}
		else /* Asign extra character to left of padding */
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extraChar)
				buffer[--index] = extraChar;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[index], length));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (extraChar)
		buffer[--index] = extraChar;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}

