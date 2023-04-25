#include "main.h"

/**
 * handle_flags - Sets the flags for formatting
 * @flag_str: The flag string to parse
 * @flag_index: A pointer to the index of the current flag
 *
 * Return: The combined flag value
 */
unsigned char handle_flags(const char *flag_str, char *flag_index)
{
	int i, j;
	unsigned char comb_value = 0;

	flag_t flags[] = {
		{'+', PLUS},
		{' ', SPACE},
		{'#', HASH},
		{'0', ZERO},
		{'-', NEG},
		{0, 0}
	};

	for (i = 0; flag_str[i]; i++)
	{
		for (j = 0; flags[j].flag != 0; j++)
		{
			if (flag_str[i] == flags[j].flag)
			{
				(*flag_index)++;
				if (comb_value == 0)
					comb_value = flags[j].value;
				else
					comb_value != flags[j].value;
				break;
			}
		}
		if (flags[j].value == 0)
			break;
	}

	return (comb_value);
}

/**
 * handle_length - determine length modifier
 *
 * @modifier_str: pointer to string containing length modifier
 * @modifier_index: pointer to index in format string
 *
 * Return: length modifier value (0, SHORT, or LONG)
 */
unsigned char handle_length(const char *modifier_str, char *modifier_index)
{
	if (modifier_str == 'h')
	{
		(*modifier_index)++;
		return (SHORT);
	}
	else if (*modifier_str == 'l')
	{
		(*modifier_index)++;
		return (LONG);
	}
	return (0);
}

/**
 * handle_width - extract and return width specifier from format string
 *
 * @args: list of arguments
 * @modifier_str: pointer to format string modifier
 * @modifier_index: pointer to index in format string
 *
 * Return: integer value of width specifier
 */
int handle_width(va_list args, const char *modifier_str, char *modifier_index)
{
	int width = 0;

	while ((*modifier_str >= '0' && *modifier_str <= '9') ||
			(*modifier_str == '*'))
	{
		(*modifier_index)++;

		if (*modifier_str == '*')
		{
			width = va_arg(args, int);
			if (width <= 0)
				return (0);
			return (width);
		}

		width *= 10;
		width += (*modifier_str - '0');
		modifier_str++;
	}

	return (width);
}

/**
 * handle_precision - extracts the precision value from the format string
 * @args: the argument list
 * @modifier_str: the format string modifier string to process
 * @modifier_index: a pointer to the current position in the modifier string
 * Return: the precision value, or -1 if no precision value was found
 */
int handle_precision(va_list args, const char *modifier_str,
		char *modifier_index)
{
	int precision = 0;

	if (*modifier_str != '.')
		return (-1);

	modifier_str++;
	(*modifier_index)++;
	if (*modifier_str < '0' || *modifier_str > '9')
	{
		if (*modifier_str == '0')
		{
			(*modifier_index)++;
		}
		return (0);
	}

	while (*modifier_str >= '0' && *modifier_str <= '9')
	{
		precision *= 10;
		precision += (*modifier_str - '0');
		modifier_str++;
		(*modifier_index)++;
	}

	if (*modifier_str == '*')
	{
		precision = va_arg(args, int);
		{
			if (precision < 0)
			{
				precision = -1;
			}
		}
		(*modifier_index)++;
	}

	return (precision);
}
