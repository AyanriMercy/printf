#include "main.h"

/**
 * _abs - computes the absolute value of an integer
 * Desription: a function
 * @ch: character to be checked
 * Return: absolute value
 */

int _abs(int ch)
{
	if (ch < 0)
	{
		ch = -ch;
	}
	return (ch);
}

/**
 * _itoa - converts an integer to a string in the specified base
 * @value: the integer to convert
 * @base: the base to convert to
 * Return: a pointer to the resulting string
 */
char *_itoa(int value, int base)
{
	char buffer[1024];
	int num, index;

	if (base < 2 || base > 32)
		exit(1);

	num = _abs(value);

	index = 0;
	while (num)
	{
		int conv = num % base;

		conv = _abs(conv);
		if (conv >= 10)
			buffer[index] = 65 + (conv - 10);
		else
			buffer[index] = 48 + conv;
		index++;
		num = num / base;
	}

	if (index == 0)
	{
		buffer[index] = '0';
		index++;
	}

	if (value < 0 && base == 10)
	{
		buffer[index] = '-';
		index++;
	}

	buffer[index] = '\0';

	return (_reverse(buffer, index));
}

/**
 * _utoa - converts an unsigned integer to a string in the specified base
 * @value: the unsigned integer to convert
 * @base: the base to use for conversion
 * Return: a pointer to the resulting string
 */

char *_utoa(unsigned int value, unsigned int base)
{
	char buffer[1024];
	unsigned int index = 0, conv;

	if (base < 2 || base > 32)
		exit(1);

	while (value)
	{
		conv = value % base;

		if (conv >= 10)
			buffer[index]  = 65 + (conv - 10);
		else
			buffer[index] = 48 + conv;

		index++;
		value /= base;
	}

	if (index == 0)
	{
		buffer[index] = '0';
		index++;
	}

	buffer[index] = '\0';

	return (_reverse(buffer, index));
}

/**
 * _lcutoa - converts an unsigned integer to a lowercase character string
 * in a given base
 * @value: the unsigned integer to convert
 * @base: the base to use for the conversion
 * Return: a pointer to the resulting character string
 */
char *_lcutoa(unsigned int value, unsigned int base)
{
	char buffer[1024];
	unsigned int index, conv;

	if (base < 2 || base > 32)
		exit(1);

	index = 0;
	while (value)
	{
		conv = value % base;

		if (conv >= 10)
		{
			buffer[index] = 65 + (conv - 10);
			if (buffer[index] >= 65 && buffer[index] <= 90)
				buffer[index] += 32;
		}
		else
			buffer[index] = 48 + conv;

		index++;
		value = value / base;
	}

	if (index == 0)
	{
		buffer[index] = '0';
		index++;
	}

	buffer[index] = '\0';

	return (_reverse(buffer, index));
}


/**
 * _uloa - Converts an unsigned long integer to a string representation in the
 * unspecified base
 * @value: the unsigned long integer value to convert.
 * @base: The base to use for the conversion. Must be between 2 and 36 inclusiv
 * Return: pointer to the string representation of the unsigned long integer
 * value in the specified base
 */
char *_uloa(unsigned long value, int base)
{
	static char buffer[32] = {0};
	int index = 0;

	while (value != 0)
	{
		unsigned long digit = value % base;
		buffer[index++] = (digit < 10) ? digit + '0' : digit - 10 + 'a';
		value /= base;
	}
	
	if (index == 0)
	{
		buffer[index++] = '0';
	}
	
	buffer[index] = '\0';
	
	return (_reverse(buffer, index));
}
