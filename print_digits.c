#include "holberton.h"

/*
 * Put here all functions related to numbers and digits
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

char *trans_number(int number, int size)
{
	char *ptr, *ptrRev;
	int i = 0, j = 0;

	ptr = malloc(size * sizeof(char) + 1);
	if (ptr == NULL)
	{
		exit(-1);
	}

	ptrRev = malloc(size * sizeof(char) + 1);
	if (ptrRev == NULL)
	{
		free(ptr);
		exit(-1);
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
 * print_char - prints a character
 *
 * @args: va_list that contains all the arguments
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

	return (_strlen(buffer) - 1);
}
