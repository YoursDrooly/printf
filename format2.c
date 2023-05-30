#include "main.h"

/**
 * print_un - Prints unsigned number
 * @type: char type
 * @array: input string in process
 * @flags: det flags
 * @width: det width
 * @precision: det precision
 * @size: det Size
 * Return: Number of printed chars
 */

int print_un(va_list type, char array[],
	int flags, int width, int precision, int size)
{
	int i = ARRAY_SIZE - 2;
	unsigned long int num = va_arg(type, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		array[i--] = '0';

	array[ARRAY_SIZE - 1] = '\0';

	while (num > 0)
	{
		array[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, array, flags, width, precision, size));
}

/**
 * print_oct - Prints an unsigned number in octal notation
 * @type: char type
 * @array: input
 * @flags: det flags
 * @width: det width
 * @precision: det precision
 * @size: det size
 * Return: Number of printed chars
 */

int print_oct(va_list type, char array[],
	int flags, int width, int precision, int size)
{

	int i = ARRAY_SIZE - 2;
	unsigned long int num = va_arg(type, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		array[i--] = '0';

	array[ARRAY_SIZE - 1] = '\0';

	while (num > 0)
	{
		array[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		array[i--] = '0';

	i++;

	return (write_unsgnd(0, i, array, flags, width, precision, size));
}

/**
 * print_hex - Prints an unsigned number in hexadecimal notation
 * @type: char type
 * @array: input
 * @flags: det flags
 * @width: det width
 * @precision: det precision
 * @size: det Size
 * Return: Number of printed chars
 */

int print_hex(va_list type, char array[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(type, "0123456789abcdef", array,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Prints unsigned number in upper hexadecimal
 * @type: char type
 * @array: input
 * @flags: det flags
 * @width: det width
 * @precision: det precision
 * @size: det size
 * Return: Number of printed chars
 */

int print_hexa_upper(va_list type, char array[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(type, "0123456789ABCDEF", array,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @type: char type
 * @map_to: array to assign hex decs
 * @array: input
 * @flags:  det flags
 * @flag_ch: detflags
 * @width: det width
 * @precision: det precision
 * @size: Size
 * Return: Number of printed chars
 */

int print_hexa(va_list type, char map_to[], char array[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = ARRAY_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		array[i--] = '0';

	array[ARRAY_SIZE - 1] = '\0';

	while (num > 0)
	{
		array[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		array[i--] = flag_ch;
		array[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, array, flags, width, precision, size));
}
