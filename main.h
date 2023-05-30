#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

int print_int(va_list l, flags_t *f);
/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
int _putchar(char c);
int _puts(char *str);

/*Functions to print char & str*/
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int widtch, int precision, int size);
int print_pecent(va_list types, char buffer[],
	int flags, int widtch, int precision, int size);
#endif
