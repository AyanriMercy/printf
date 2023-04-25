#ifndef MAIN_H
#define MAIN_H

/* LIBRARIES */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>

/* ASSIGNER FUNCTIONS */

int _assign(char *buff, int count, char *value);
int _rev_assign(char *buff, int count, char *value);

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

/*  PARAMETER CHECKER FUNCTION */

int (*check_prtr(char specifier))(char *, int, va_list);

/* PRINTF FUNCTION */

int _printf(const char *format, ...);

/* STRING MANIPULATION FUNCTION */

char *rot13(char *word);
char *_reverse(char *s, int n);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
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

#endif
