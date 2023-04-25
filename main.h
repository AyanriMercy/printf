#ifndef MAIN_H
#define MAIN_H

/* LIBRARIES */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>

/* Flag Modifier Macros */

#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define PLUS_FLAG (flags & 1)
#define SPACE_FLAG ((flags >> 1) & 1)
#define HASH_FLAG ((flags >> 2) & 1)
#define ZERO_FLAG ((flags >> 3) & 1)
#define NEG_FLAG ((flags >> 4) & 1)

/* Length Modifier Macros */
#define SHORT 1
#define LONG 2

/* ASSIGNER FUNCTIONS */

int _assign(char *buff, int count, char *value);
int _rev_assign(char *buff, int count, char *value);

/* CALLBACK FUNCTIONS */

unsigned char handle_flags(const char *flag_str, char *flag_index);
unsigned char handle_length(const char *modifier_str, char *modifier_index);
int handle_width(va_list args, const char *modifier_str, char *modifier_index);
int handle_precision(va_list args, const char *modifier_str,
		char *modifier_index);

/* FORMAT SPECIFIERS */

unsigned int print_width(buffer_t *buffer, unsigned int num_print,
		unsigned char conv_flags, int field_wid);
unsigned int print_string_width(buffer_t *buffer, unsigned int num_print,
		unsigned char conv_flags, int field_wid,
		int precision, int string_size);
unsigned int print_neg_width(buffer_t *buffer, unsigned int num_print,
		unsigned char conv_flags, int field_wid);

/* OUTPUT FORMATTING FUNCTIONS */

int func_d(char *buff, int count, va_list value);
int func_i(char *buff, int count, va_list value);
int func_u(char *buff, int count, va_list value);
int func_o(char *buff, int count, va_list value);
int func_x(char *buff, int count, va_list value);
int func_X(char *buff, int count, va_list value);
int func_c(char *buff, int count, va_list value);
int func_s(char *buff, int count, va_list value);
int func_R(char *buff, int count, va_list value);
int func_ptg(char *buff, int count, va_list value);
int func_b(char *buff, int count, va_list value);
int func_r(char *buff, int count, va_list value);
int func_p(char *buff, int count, va_list value);

/* NUMBER FUNCTIONS */

int _abs(int ch);
char *_itoa(int value, int base);
char *_utoa(unsigned int value, unsigned int base);
char *_lcutoa(unsigned int value, unsigned int base);
unsigned int convert_ubase(buffer_t *output, unsigned long int num, char *base,
		unsigned char flags, int wid, int prec);

/*  PARAMETER CHECKER FUNCTION */

int (*check_param(char specifier))(char *, int, va_list);

/* PRINTF FUNCTION */

int _printf(const char *format, ...);
void cleanup(va_list args, buffer_t *output);
int run_printf(const char *format, va_list args, buffer_t *output);

/* STRING MANIPULATION FUNCTION */

char *rot13(char *word);
char *_reverse(char *s, int n);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
int _putchar(char c);


/* STRUCTURES */

/**
 * struct ptr - parameters and functions struct
 * @c: parameter indicator
 * @f: parameter function
 */
typedef struct ptr
{
	char *c;
	int (*f)(char *, int, va_list);
} ptr_ch;

/**
 * struct buffer_s - A new type defining a buffer struct.
 * @buffer: A pointer to a character array.
 * @start: A pointer to the start of buffer.
 * @len: The length of the string stored in buffer.
 */
typedef struct buffer_s
{
	char *buffer;
	char *start;
	unsigned int len;
} buffer_t;

/**
 * struct converter_s - A new type defining a converter struct.
 * @specifier: A character representing a conversion specifier.
 * @func: A pointer to a conversion function corresponding to specifier.
 */
typedef struct converter_s
{
	unsigned char specifier;
	unsigned int (*func)(va_list, buffer_t *,
			unsigned char, int, int, unsigned char);
} converter_t;

/**
 * struct flag_s - A new type defining a flags struct.
 * @flag: A character representing a flag.
 * @value: The integer value of the flag.
 */
typedef struct flag_s
{
	unsigned char flag;
	unsigned char value;
} flag_t;

#endif
