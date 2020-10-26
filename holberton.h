#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>

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
	char *(*f)(va_list);
} specifier;

#endif
