#include "holberton.h"

int _strlen(char *buffer)
{
	int size = 0;

	while (buffer[size] != '\0')
	{
		size++;
	}
	return (size);
}

/**
 * _printf - function printf
 * @format: specifier format
 * Return: size of printed buffer
 */

int _printf(const char *format, ...)
{
	int i = 0, j, aux = 0, totalSize = 0;
	va_list args;
	char *buffer;

	buffer = malloc(1024 * sizeof(char));
	if (!buffer)
		exit(-1);
	specifier specifiers[] = {
		{'c', print_char},
		{'d', print_int},
		{'i', print_int},
		{'%', print_percent},
		{'\0', NULL}
	};
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (i != 0)
			{
				if (format[i - 1] == '%')
				{
					i++;
					aux++;
					continue;
				}
			}
			j = 0;
			while (specifiers[j].type != '\0')
			{
				if (specifiers[j].type == format[i + 1])
				{
					aux = specifiers[j].f(args, buffer, aux);
					break;
				}
				j++;
			}
		} else
		{
			if (i != 0)
			{
				if (format[i - 1] == '%')
				{
					if (format[i - 2] == '%')
						buffer[aux] = format[i];
				} else
					buffer[aux] = format[i];
			}
			else
				buffer[aux] = format[i];
			aux++;
		}
		i++;
	}
	buffer[aux] = '\0';
	totalSize = _strlen(buffer);
	write(1, buffer, totalSize);
	free(buffer);
	va_end(args);
	return (totalSize);
}
