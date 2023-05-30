#include "main.h"


/**
 * print_pointer - Prints pointer variable value
 * @type: char type
 * @array: input
 * @flags:  det flags
 * @width: det width
 * @precision: det precision
 * @size: det size
 * Return: Number of printed chars
 */

int print_pointer(va_list type, char array[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = ARRAY_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(type, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	array[ARRAY_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		array[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	return (write_pointer(array, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @type: typr od char
 * @array: input
 * @flags:  det flags
 * @width: det width
 * @precision: det precision
 * @size: det size
 * Return: Number of printed chars
 */

int print_non_printable(va_list type, char array[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(type, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			array[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], array, i + offset);

		i++;
	}

	array[i + offset] = '\0';

	return (write(1, array, i + offset));
}

/**
 * print_r - Print reverse of a string
 * @type: type of char
 * @array: input
 * @flags:  det flags
 * @width: det width
 * @precision: det precision
 * @size: det size
 * Return: Numbers of printed chars
 */

int print_r(va_list type, char array[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(array);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(type, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - Print a string in rot13.
 * @type: type of char
 * @array: input array
 * @flags:  det flags
 * @width: det width
 * @precision: det precision
 * @size: det size
 * Return: Numbers of printed chars
 */

int print_rot13string(va_list type, char array[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(type, char *);
	UNUSED(array);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
