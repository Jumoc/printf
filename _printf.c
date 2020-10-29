#include "holberton.h"
/**
 * _strlen - function that obtain the length of buffer
 * @buffer: pointer contain digits
 * Return: size of buffer
 */
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
 * _strlen_const - function that obtain the length of buffer
 * @buffer: pointer contain digits
 * Return: size of buffer
 */
int _strlen_const(const char *buffer)
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
	int i = 0, j, aux = 0, totalSize = 0, bo = 0;
	va_list args;
	char *buffer;
	specifier specifiers[] = {{'c', print_char}, {'d', print_int},
				  {'i', print_int}, {'s', print_string}, {'%', print_percent},
				  {'\0', NULL}
	};

	buffer = malloc(1024 * sizeof(char));
	if (!buffer || !format || (format[i] == '%' && _strlen_const(format) == 1))
		exit(-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			j = 0;
			while (specifiers[j].type != '\0')
			{
				if (specifiers[j].type == format[i + 1])
				{
					aux = specifiers[j].f(args, buffer, aux);
					bo = 1;
				}
				j++;
			}
			if (bo == 0)
			{
				buffer[aux++] = format[i];
				buffer[aux++] = format[i + 1];
			} else
				bo = 0;

			i++;
		} else
		{
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
