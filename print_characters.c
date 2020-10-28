#include "holberton.h"
/*
The idea is to put all functions that print characters here
that way there's few files at the end
*/

/**
 * print_char - prints a character
 * 
 * @args: va_list that contains all the arguments
 * @buffer: buffer that contains the string to be printed
 * @size: size or index where the new character is going to be added
 * 
 * Return: size of the buffer
 */
int print_char(va_list args, char* buffer, int size)
{

	buffer[size] = va_arg(args, int);
	buffer[size + 1] = '\0';
    
	return (_strlen(buffer) - 1);
}

/**
 * print_percent - prints a percent
 * 
 * @buffer: buffer that contains the string to be printed
 * @size: size or index where the new character is going to be added
 * 
 * Return: size of the buffer
 */
int print_percent(va_list args, char* buffer, int size)
{
	(void)args;
	buffer[size] = '%';
	buffer[size + 1] = '\0';
    
	return (_strlen(buffer) - 1);
}