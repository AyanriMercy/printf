#include "main.h"

/**
 * func_X - converts an unsigned integer argument to a uppercase hexadecimal
 * string and assigns it to a buffer
 * @buff: pointer to the buffer
 * @count: maximum number of bytes to be written to the buffer
 * @value: va_list containing the unsigned integer argument
 * Return: the number of bytes written to the buffer, or -1 on failure
 */
int func_X(char *buff, int count, va_list value)
{
	int base = 16;
	unsigned int integer = va_arg(value, unsigned int);
	int i;
	char *string = _utoa(integer, base);

	if (!string)
		return (-1);

	i = 0;
	for (i = 0; string[i]; i++)
	{
		if (string[i] >= 'a' && string[i] <= 'f')
			string[i] = string[i] - 'a' + 'A';
	}

	count = _assign(buff, count, string);

	free(string);
	return (count);
}

/**
 * func_c - writes a character to the buffer
 * @buff: buffer to store the string
 * @count: current count of printed characters
 * @value: argument passed
 * Return: updated count
 */
int func_c(char *buff, int count, va_list value)
{
	int chars = va_arg(value, int);

	if (!chars)
	{
		write(1, "\0\0", 2);
		free(buff);
		exit(0);
	}
	buff[0] = chars;
	return (count + 1);
}

/**
 * func_s - prints a string
 * @buff: buffer to store the string
 * @count: current count of printed characters
 * @value: argument list containing a string toprint
 * Return: the number of characters printed
 */
int func_s(char *buff, int count, va_list value)
{
	char *string = va_arg(value, char *);

	if (!string)
		string = "(null)";

	return (_assign(buff, count, string));
}

/**
 * func_R - encodes a string argument using ROT13 and asssigns it to a buffer
 * @buff: pointer to the buffer
 * @count: maximum number of bytes to be written to the buffer
 * @value: va_list containing the string argument
 * Return: number of bytes writtn to the buffer, or -1 on failure
 */
int func_R(char *buff, int count, va_list value)
{
	char *string = va_arg(value, char *);
	char *enc_string = malloc(sizeof(char) * (_strlen(string) + 1));

	if (!enc_string)
		return (-1);

	_strcpy(enc_string, string);
	rot13(enc_string);

	count = _assign(buff, count, enc_string);

	free(enc_string);
	return (count);
}

/**
 * func_ptg - adds a '%' character to buff and returns updated count
 * @buff: pointer to buff
 * @count: current count
 * @value: va_list value
 * Return: updated count
 */
int func_ptg(char *buff, int count, va_list value)
{
	(void)value;

	buff[0] = '%';
	return (count + 1);
}
