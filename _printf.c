#include "holberton.h"
/**
 * _printf - function printf
 * @format: specifier format
 */

int _printf(const char *format, ...)
{
	int i = 0, j;
	va_list ap;
	specifier arr[] = {{'c', print_char},
			    {'d', print_decimal},
			    {'u', print_unsigned_decimal}
			    {'i', print_integer},
			    {'s', print_string},
			    {'o', print_unsigned_octal},
			    {'x', print_unsigned_hexidecimal},
			    {'X', print_unsigned_dec_upper},
			    {'S', print_string_upper},
			    {'p', print_pointer_address},
			    {'f', print_floating_point},
			    {'b', print_binary},
			    {'r', print_reversed},
			    {'R', print_rot13},
		    };
	va_start(ap, format);
	while (format[i] != '0' && format != NULL)
	{
		if (format[i] == '%')
		{
			j = 0;
			while (j < 14)
			{
				if (format[i + 1] == arr[j].type)
				{
					arr[j].f(ap);
					break;
				}
				j++;
			}
		}
		i++;
	}
	va_end(ap);
	return (buffer);
}
