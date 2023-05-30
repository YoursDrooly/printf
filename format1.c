#include "main.h"

/**
 * print_c - prints character
 * @type: character type
 * @array: input string
 * @flags: determines flags
 * @width: determines width
 * @precision: determines precision
 * @size: determines size
 * Return: number of printed characters
 */

int print_c(va_list type, char array[],
		int flags, int width, ont precision, int size)
{
	char c = va_arg(type, int);

	return (print_type(c, array, flags, width, precision, size));
}

/**
 * print_s - prints string
 * @type: character typer
 * @array: input string to print
 * @flags: determines flags
 * @size: det size
 * @width: determines width
 * @precision: determines precision
 * Return: Number of printed characters
 */

int print_s(va_list type, char array[],
		int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(type, char *);

	UNUSED(array);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}

/**
 * print_percentage- Print percentage sign
 * @type: type of charcater
 * @array: input string to print
 * @flags: determines flags
 * @width: determines width
 * @precision: determines precision
 * @size: determines size
 * Return: Number of printed characters
 */

int print_percentage(va_list type, char array[],
		int flags, int width, int precision, int size)
{
	UNUSED(type);
	UNUSED(array);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_i - print integer
 * @type: type of character
 * @array: input string to rpint
 * @flags: determines flags
 * @width: determines width
 * @precision: det precision
 * @size: det size
 * Return: number of printed characters
 */

int print_i(va_list type, char array[],
		int flags, int width, int precision, int size)
{
	int i = ARRAY_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(type, long_int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		array[i--] = '0';

	array[ARRAY_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
			is_negative = 1;
	}

	while (num > 0)
	{
		array[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, array, flags, width, precision, size));

}

/**
 * print_b - print binary
 * @type: char type
 * @array: input
 * @flags: det flags
 * @width: det width
 * @precision: det precision
 * @size: det size
 * Return: number of printed char
 */

int print_b(va_list type, char array[],
		int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;

	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}

	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
