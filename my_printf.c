#include "main.h"

void apply_operation(const char *format, int *num, int *cnt, op_t ops[],
		va_list arg_ptr, int *found);

/**
 * apply_operation - processes the format strings
 * Description: a function that processes the format string based on th
 * operations defined in the 'ops' array and the arguments provided in the
 * 'arg_ptr' list.
 * @format: pointer to a character array representing the format string
 * @num: pointer to an int representing current position of the iterator
 * @cnt: pointer to an int representing the character count processed so fa
 * @ops: array of structures that define the operations to be applies to
 * format string
 * @arg_ptr: pointer to list of arguments to be processes by format string
 * @found: point to integer representing whether specifier is found in format
 * string or not
 * Return: no return value
 */

void apply_operation(const char *format, int *num, int *cnt, op_t ops[],
		va_list arg_ptr, int *found)
{
	int index, chars;

	if (*(format + *num + 1) == '%')
	{
		_putchar('%');
		*cnt += 1;
		*found = 1;
		*num += 1;
	}
	else
	{
		index = 0;
		while ((ops + index)->op)
		{
			if (*((ops + index)->op) == *(format + *num + 1))
			{
				chars = (ops + index)->f(arg_ptr);
				*cnt += chars;
				*found = 1;
				*num += 1;
				break;
			}
			index++;
		}
	}
}

int _printf(const char *format, ...);

/**
 * _printf - print formatted output to the standard output stream
 * @format: string of characters
 * Return: integer, which represents total numbeer of characters to be printed
 */

int _printf(const char *format, ...)
{
	va_list arg_ptr;
	int num, cnt = 0, found = 0;
	op_t ops[] = {
		{"c", character}, {"s", string}, {"d", integer}, {"i", integer},
		{"u", u_integer}, {"b", binary}, {"o", octal}, {"x", hexa_lower},
		{"X", hexa_upper}, {"S", custom_string}, {NULL, NULL}
	};

	va_start(arg_ptr, format);

	if (!format || !format[1])
	{
		return (-1);
	}
	while (*(format + num))
	{
		found = 0;
		if (*(format + num) == '%')
		{
			apply_operation(format, &num, &cnt, ops, arg_ptr, &found);

			if (found == 0 && *(format + num + 1) != '\0')
			{
				_putchar(*(format + num));
				cnt++;
			}
		}
		else
		{
			_putchar(*(format + num));
			cnt++;
		}
		num++;
	}
	va_end(arg_ptr);

	return (cnt);
}
