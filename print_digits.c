#include "holberton.h"

/**
 * count_digits - Counter arrays
 * @number: value have counted
 * Return: size
 */

int count_digits(int number)
{
	int size = 0;

	while (number != 0)
	{
		number /= 10;
		size++;
	}

	return (size);
}

/**
 * trans_number - Pointer that contain the revert numbers
 * @number: to revert
 * @size: size of array
 * Return: pointer revert
 */

char *trans_number(int number, int size)
{
	char *ptr, *ptrRev;
	int i = 0, j = 0;

	ptr = malloc(size * sizeof(char) + 1);
	if (ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}

	ptrRev = malloc(size * sizeof(char) + 1);
	if (ptrRev == NULL)
	{
		free(ptr);
		free(ptrRev);
		return (NULL);
	}
/*
 * puts the number in the array, but reversed
 */
	while (i < size)
	{
		ptr[i] = (number % 10) + '0';
		number /= 10;
		i++;
	}
	ptr[i] = '\0';
/*
 * reverses the array
 */
	while (ptr[j] != '\0')
	{
		ptrRev[j] = ptr[i - 1];
		i--;
		j++;
	}
	ptrRev[j] = '\0';
	free(ptr);
	return (ptrRev);
}

/**
 * print_int - prints a integer number
 *
 * @args: va_list that contains all the arguments
 * @buffer: buffer that contains the string to be printed
 * @size: size or index where the new character is going to be added
 * Return: size of the buffer
 */
int print_int(va_list args, char *buffer, int size)
{
	int i = 0;
	int num, digits;
	char *numbers;

	num = va_arg(args, int);

	if (num < 0)
	{
		buffer[size] = '-';
		num *= -1;
		size++;
	}
	if (num == 0)
	{
		buffer[size] = '0';
		buffer[size + 1] = '\0';
		return (_strlen(buffer));
	}

	digits = count_digits(num);

	numbers = trans_number(num, digits);

	while (i < digits)
	{
		buffer[size] = numbers[i];
		size++;
		i++;
	}

	free(numbers);

	buffer[size] = '\0';

	return (_strlen(buffer));
}
