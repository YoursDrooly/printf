#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

int print_int(va_list l, flags_t *f);
int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);

/* format by type */
int print_c(va_list type, char array[],
		int flags, int width, int precision, int size);
int print_s(va_list type, char array[],
		int flags, int width, int precision, int size);
int print_percentage(va_list type, char array[],
		int flags, int width, int precision, int size);
int print_i(va_list type, char array[],
		int flags, int width, int precision, int size);
int print_b(va_list type, char array[],
		int flags, int width, int precision, int size);
int print_un(va_list type, char array[],
	int flags, int width, int precision, int size);
int print_oct(va_list type, char array[],
	int flags, int width, int precision, int size);
int print_hex(va_list type, char array[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list type, char array[],
	int flags, int width, int precision, int size);
int print_hexa(va_list type, char map_to[], char array[],
	int flags, char flag_ch, int width, int precision, int size);
int print_pointer(va_list type, char array[],
	int flags, int width, int precision, int size);
int print_non_printable(va_list type, char array[],
	int flags, int width, int precision, int size);
int print_r(va_list type, char array[],
	int flags, int width, int precision, int size);
int print_rot13string(va_list type, char array[],
	int flags, int width, int precision, int size);
int print_pointer(va_list type, char array[],
	int flags, int width, int precision, int size);
int print_non_printable(va_list type, char array[],
	int flags, int width, int precision, int size);
int print_r(va_list type, char array[],
	int flags, int width, int precision, int size);
int print_rot13string(va_list type, char array[],
	int flags, int width, int precision, int size);
int handle_print(const char *fmt, int *ind, va_list list, char array[],
	int flags, int width, int precision, int size);
int handle_write_char(char c, char array[],
	int flags, int width, int precision, int size);
int write_number(int is_negative, int ind, char array[],
	int flags, int width, int precision, int size);
int write_num(int ind, char array[],
	int flags, int width, int prec,
	int length, char padd, char extra_c);
int write_unsgnd(int is_negative, int ind,
	char array[],
	int flags, int width, int precision, int size);
int write_pointer(char array[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);


/* utility stuff */
int is_printable(char c);
int append_hexa_code(char ascii_code, char buffer[], int i);
int is_digit(char c);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
