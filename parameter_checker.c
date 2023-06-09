#include "main.h"

/**
 * check_prtr - selects the appropriate conversion function
 * @specifier: the format specifier character
 * Return: pointer to the corresponding conversion function
 */
int (*check_prtr(char specifier))(char *, int, va_list)
{
	int byte = 0;

	ptr_ch arg_ptr[] = {
		{"d", func_d},
		{"i", func_i},
		{"u", func_u},
		{"o", func_o},
		{"x", func_x},
		{"X", func_X},
		{"c", func_c},
		{"%", func_ptg},
		{"b", func_b},
		{"R", func_R},
		{"r", func_r},
		{"s", func_s},
		{"p", func_p},
		{NULL, NULL}
	};

	while (arg_ptr[byte].c)
	{
		if (specifier == *arg_ptr[byte].c)
			break;
		byte++;
	}

	return (arg_ptr[byte].f);
}
