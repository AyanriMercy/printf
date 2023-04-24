#include "main.h"

/**
 * func_d - converts an integer argument to a string and assigns it to a buffer
 * @buff: pointer to the buffer
 * @count: maximum number of bytes to be written to the buffer
 * @value: va_list containing the integer argument
 * Return: the number of bytes written to the buffer, or -1 on failure
 */
int func_d(char *buff, int count, va_list value)
{
	int base = 10;
	char *string = _itoa(va_arg(value, int), base);

	return (_assign(buff, count, string));
}

/**
 * func_i - converts an integer argument to a string and assigns it to a buffer
 * @buff: pointer to the buffer
 * @count: maximum number of bytes to be written to the buffer
 * @value: va_list containing the integer argument
 * Return: the number of bytes written to the buffer, or -1 on failure
 */
int func_i(char *buff, int count, va_list value)
{
	int base = 10;
	char *string = _itoa(va_arg(value, int), base);

	if (!string)
		return (-1);

	count = _assign(buff, count, string);

	free(string);
	return (count);
}

/**
 * func_u - converts an unsigned integer argument to a string and
 * assigns it to a buffer
 * @buff: pointer to the buffer
 * @count: maximum number of bytes to be written to the buffer
 * @value: va_list containing the unsigned integer argument
 * Return: the number of bytes written to the buffer, or -1 on failure
 */
int func_u(char *buff, int count, va_list value)
{
	int base = 10;
	unsigned int integer = va_arg(value, unsigned int);
	char *string = _utoa(integer, base);

	if (!string)
		return (-1);

	count = _assign(buff, count, string);

	free(string);
	return (count);
}

/**
 * func_o - converts an unsigned integer argument to an octal string and
 * assigns it to a buffer
 * @buff: pointer to the buffer
 * @count: maximum number of bytes to be written to the buffer
 * @value: va_list containing the unsigned integer argument
 * Return: the number of bytes written to the buffer, or -1 on failure
 */
int func_o(char *buff, int count, va_list value)
{
	int base = 8;
	unsigned int integer = va_arg(value, unsigned int);
	char *string = _utoa(integer, base);

	if (!string)
		return (-1);

	count = _assign(buff, count, string);

	free(string);
	return (count);
}

/**
 * func_x - converts an unsigned integer argument to a lowercase hexadecimal
 * string and assigns it to a buffer
 * @buff: pointer to the buffer
 * @count: maximum number of bytes to be written to the buffer
 * @value: va_list containing the unsigned integer argument
 * Return: the number of bytes written to the buffer, or -1 on failure
 */
int func_x(char *buff, int count, va_list value)
{
	int base = 16;
	unsigned int integer = va_arg(value, unsigned int);
	char *string = _lcutoa(integer, base);

	if (!string)
		return (-1);

	count = _assign(buff, count, string);

	free(string);
	return (count);
}
