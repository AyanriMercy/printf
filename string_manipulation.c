#include "main.h"

/**
 * *rot13 - encodes a string using rot13
 * Description: a function that  simple letter substitution cipher that
 * replaces a letter with the letter 13 letters after it in the alphabet
 * @word: string to be checked
 * Return: string ciphered with Rot13
 */
char *rot13(char *word)
{
	int a, b;
	char letter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char replce[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (a = 0; word[a] != '\0'; a++)
	{
		for (b = 0; b < 54; b++)
		{
			if (((word[a] <= 'z' && word[a] >= 'a') || (word[a] <= 'Z' &&
						word[a] >= 'A')) && word[a] == letter[b])
			{
				word[a] = replce[b];
				break;
			}
		}
	}
	return (word);
}

/**
 * _reverse - reverses a string in place
 * @s: pointer to the string to be reversed
 * @n: length of the string
 * Return: pointer to the reversed string
 */
char *_reverse(char *s, int n)
{
	int i = 0;
	int j;
	char temp;

	if (s == NULL)
		return (NULL);
	
	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}

	return (s);
}

/**
 * *_strcpy - copies the string pointed to by src, including the terminating
 * null byte (\0), to the buffer pointed to by dest
 * @src: string pointer
 * @dest: array
 * Description: a funcyion
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int a = 0;
	int lng = 0;

	while (src[a] != '\0')
	{
		a++;
	}

	lng = a;
	for (a = 0; a < lng && src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	for ( ; a <= lng; a++)
	{
		dest[a] = '\0';
	}
	return (dest);
}

/**
 * _strlen - returns the length of a string
 * @s: character to be checked
 * Description: a function
 * Return: string length
 */
int _strlen(char *s)
{
	int lng = 0;

	while (*s != '\0')
	{
		s++;
		lng++;
	}
	return (lng);
}
