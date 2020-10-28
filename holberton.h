#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct specifier - struct that holds a function and a char
 *
 * @type: type of format
 * @f: function that prints
 *
 */

typedef struct specifier
{
	char type;
	int (*f)(va_list, char *, int);
} specifier;

int print_char(va_list args, char *, int);
int _printf(const char *format, ...);
int _strlen(char *buffer);
int print_int(va_list args, char* buffer, int size);
int print_percent(va_list args, char* buffer, int size);

#endif
