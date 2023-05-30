#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/**
 * struct fmt - for handle printing
 * @fmt: format type
 * @fn: function for the type
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - for printing
 * @fmt: format type
 * @fm_t: function for the type
 */
typedef struct fmt fmt_t;

/* task 0 printing */
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *ind, va_list list, char buffer[]);

/* task 0 format type */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* task 1 format type */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);

#endif
