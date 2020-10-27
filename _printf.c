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

	specifier specifiers[] = {
		{'c', print_char},
		{'i', print_int},
		{'\0', NULL}
	};

	va_start(args, format);

	while (format[i] != '\0')
	{
		if(format[i] == '%')
		{
		j = 0;
		while (specifiers[j].type != '\0')
		{
			if (specifiers[j].type == format[i + 1])
			{
				aux = specifiers[j].f(args, buffer, aux);
			}
			j++;
		}
		} else
		{
			if (i != 0)
			{
				if (format[i - 1] != '%')
				{
					buffer[aux] = format[i];
				}
			}
			else
			{
				buffer[aux] = format[i];
			}
			aux++;
		}
		i++;
	}
	totalSize = _strlen(buffer);
	write(1, buffer, totalSize);
	free(buffer);
	va_end(args);
	return(totalSize);
}
