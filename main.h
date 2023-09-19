#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/* SIZES */
#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
 * struct Format - Struct for format specifier
 *
 * @format: The format.
 * @function: The associated function.
 */
struct Format
{
	char format;
	int (*function)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct Format Format_t - Typedef for struct Format
 *
 * @format: The format.
 * @function: The associated function.
 */
typedef struct Format Format_t;

int custom_printf(const char *format, ...);
int handle_print(const char *formatSpecifier, int *index,
	va_list argsList, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Functions to print characters and strings */
int printCharacter(va_list argsList, char buffer[],
	int flags, int width, int precision, int size);
int printString(va_list argsList, char buffer[],
	int flags, int width, int precision, int size);
int printPercentSign(va_list argsList, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int printInteger(va_list argsList, char buffer[],
	int flags, int width, int precision, int size);
int printBinary(va_list argsList, char buffer[],
	int flags, int width, int precision, int size);
int printUnsigned(va_list argsList, char buffer[],
	int flags, int width, int precision, int size);
int printOctal(va_list argsList, char buffer[],
	int flags, int width, int precision, int size);
int printHexadecimal(va_list argsList, char buffer[],
	int flags, int width, int precision, int size);
int printHexadecimalUpper(va_list argsList, char buffer[],
	int flags, int width, int precision, int size);

int printHexadecimal(va_list argsList, char mapTo[], char buffer[],
	int flags, char flagChar, int width, int precision, int size);

/* Function to print non-printable characters */
int printNonPrintable(va_list argsList, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print memory address */
int printPointer(va_list argsList, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int getFlags(const char *format, int *index);
int getWidth(const char *format, int *index, va_list argsList);
int getPrecision(const char *format, int *index, va_list argsList);
int getSize(const char *format, int *index);

/* Function to print a string in reverse */
int printReverse(va_list argsList, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print a string in ROT13 */
int printRot13String(va_list argsList, char buffer[],
	int flags, int width, int precision, int size);

/* Width handler functions */
int handleWriteCharacter(char c, char buffer[],
	int flags, int width, int precision, int size);
int writeNumber(int isPositive, int index, char buffer[],
	int flags, int width, int precision, int size);
int writeNumeric(int index, char bff[], int flags, int width, int precision,
	int length, char padding, char extraCharacter);
int writePointer(char buffer[], int index, int length,
	int width, int flags, char padding, char extraCharacter, int paddingStart);

int writeUnsigned(int isNegative, int index,
	char buffer[], int flags, int width, int precision, int size);

/****************** UTILS ******************/
int isPrintable(char character);
int appendHexadecimalCode(char c, char hexArray[], int index);
int isDigit(char character);

long int convertSizeNumber(long int num, int size);
long int convertSizeUnsigned(unsigned long int num, int size);

#endif /* MAIN_H */

