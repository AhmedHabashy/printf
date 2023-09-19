#include "main.h"

/**
 * getFlags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: Index in the format string.
 * Return: Flags:
 */
int getFlags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, currentIndex;
	int flags = 0;
	const char FLAGS_CHARACTERS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (currentIndex = *i + 1; format[currentIndex] != '\0'; currentIndex++)
	{
		for (j = 0; FLAGS_CHARACTERS[j] != '\0'; j++)
			if (format[currentIndex] == FLAGS_CHARACTERS[j])
			{
				flags |= FLAGS_ARRAY[j];
				break;
			}

		if (FLAGS_CHARACTERS[j] == 0)
			break;
	}

	*i = currentIndex - 1;

	return (flags);
}

