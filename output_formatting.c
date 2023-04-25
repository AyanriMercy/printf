#include "main.h"

/**
 * func_b - converts an unsigned integer to binary and adds it to a buffer
 * @buff: buffer to add the converted integer to
 * @count: current number of bytes in the buffer
 * @value: va_list containing the unsigned integer to convert
 * Return: new numbeer of bytes in the buffer
 */
int func_b(char *buff, int count, va_list value)
{
	unsigned int integer;
	char *string;
	int index = 2;

	integer = va_arg(value, unsigned int);
	string = _utoa(integer, index);

	return (_assign(buff, count, string));
}

/**
 * func_r - adds a reversed string to buff
 * @buff: the buffer to add the reversed string to
 * @count: the number of characters in the buffer so far
 * @value: the va_list that contains the string to reverse
 * Return: the new count of characters in the buffer
 */
int func_r(char *buff, int count, va_list value)
{
	char *string = va_arg(value, char *);
	int length = _strlen(string);
	int index;

	for (index = 0; index < length / 2; index++)
	{
		char temp = string[index];

		string[index] = string[length - index - 1];
		string[length - index - 1] = temp;
	}

	return (_assign(buff, count, string));
}

/**
 * func_p - prints a pointer address in memory
 * @buff: pointer to character array where output of fucntion will be stored
 * @count: integer current count of characters in buffer
 * @value: va_list containing a pointer to value to be printed as address
 * Return: new count of characters in the buffer after address is printed
 */
int func_p(char *buff, int count, va_list value)
{
	int base = 16;
	void *ptr;
	char *string;

	ptr = va_arg(value, void*);
	string = _utoa((unsigned long)ptr, base);

	return (_assign(buff, count, string));
}
