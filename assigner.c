#include "main.h"

/**
 * _assign - assigns the characters from the value string to the buff string
 * starting at the index count. returns the new count of characters in buff
 * @buff: pointer to a string buffer to which characters will be assigned
 * @count: starting index in the buff string at which to begin assigning chars
 * @value: pointer to a string conatining the characters to be assigned to buff
 * Return: new count of characters in the buff string after the assignment
 */
int _assign(char *buff, int count, char *value)
{
	int index = 0;

	while (value[index])
	{
		buff[index] = value[index];
		count++;
		index++;
	}

	return (count);
}

/**
 * _rev_assign - reverses and assigns a string to a buffer
 * @buff: buffer to assign the reversed string
 * @count: starting index to assign the reversed string
 * @value: string to be reversed and assigned
 * Return: updated count after assigning the reversed string
 */
int _rev_assign(char *buff, int count, char *value)
{
	int length = _strlen(value);
	int index;

	for (index = 0; index < length; index++)
	{
		buff[count + index] = value[length - index - 1];
	}
	count += length;

	return (count);
}
