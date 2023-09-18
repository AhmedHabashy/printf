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
int _puts(char *str);
int print_char(va_list *ptr);
int print_string(va_list *ptr);

/* handlers */
int print_handler(char const *format, va_list *ptr);
#endif
