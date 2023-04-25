#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	char *buff;
	int index = 0, count = 0;
	va_list args;
	int (*func)(char *, int, va_list);

	buff = malloc(4000);
	if (!buff)
		exit(1);

	if (!format || (format[0] == '%' && format[1] == '\0'))
	{
		free(buff);
		return (-1);
	}
	va_start(args, format);
	while (format[index])
	{
		if (format[index] != '%')
		{
			buff[count] = format[index];
			count++;
		}
		else
		{
			func = check_prtr(format[index + 1]);
			if (!func)
			{
				buff[count] = '%';
				count++;
			}
			else
				count = func(&buff[count], count, args);
			index++;
		}
		index++;
	}
	write(1, buff, count);
	va_end(args);
	free(buff);
	return (count);
}
