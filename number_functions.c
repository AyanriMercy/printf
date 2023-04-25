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
 * convert_ubase - Converts an unsigned long to an inputted base and
 *                 stores the result to a buffer contained in a struct.
 * @output: A buffer_t struct containing a character array.
 * @num: An unsigned long to be converted.
 * @base: A pointer to a string containing the base to convert to.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_ubase(buffer_t *output, unsigned long int num, char *base,
		unsigned char flags, int wid, int prec)
{
	unsigned int size, ret = 1;
	char digit, pad = '0', *lead = "0x";

	for (size = 0; *(base + size);)
		size++;

	if (num >= size)
		ret += convert_ubase(output, num / size, base,
				flags, wid - 1, prec - 1);

	else
	{
		if (((flags >> 5) & 1) == 1)
		{
			wid -= 2;
			prec -= 2;
		}
		for (; prec > 1; prec--, wid--)
			ret += _memcpy(output, &pad, 1);

		if (NEG_FLAG == 0)
		{
			pad = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; wid > 1; wid--)
				ret += _memcpy(output, &pad, 1);
		}
		if (((flags >> 5) & 1) == 1)
			ret += _memcpy(output, lead, 2);
	}

	digit = base[(num % size)];
	_memcpy(output, &digit, 1);

	return (ret);
}
