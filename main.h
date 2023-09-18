#ifndef MAIN_H
#define MAIN_H
/* libraries */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/* main printing function*/
int _printf(const char *format, ...);

/* printing functions */
int _putchar(char c);
void _puts(char *str);
void print_char(va_list *ptr);
void print_string(va_list *ptr);

/* handlers */
void print_handler(char format, va_list *ptr);
#endif

