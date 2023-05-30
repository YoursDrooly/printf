#include "main.h"

/**
 * handle_write_char - Prints a string
 * @c: char types
 * @array: input array to prinbt
 * @flags:  det flags
 * @width: det width
 * @precision: det precision
 * @size: det size
 * Return: Number of printed chars printed
 */

int handle_write_char(char c, char array[],
	int flags, int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	array[i++] = c;
	array[i] = '\0';

	if (width > 1)
	{
		array[ARRAY_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			array[ARRAY_SIZE - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &array[0], 1) +
					write(1, &array[ARRAY_SIZE - i - 1], width - 1));
		else
			return (write(1, &array[ARRAY_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &array[0], 1));
}

/**
 * write_number - Prints a string
 * @is_negative: flag to see if input is negative
 * @ind: char types
 * @array: input array to print
 * @flags:  det flags
 * @width: det width
 * @precision: det precision
 * @size: det Size
 * Return: Number of printed chars
 */

int write_number(int is_negative, int ind, char array[],
	int flags, int width, int precision, int size)
{
	int length = ARRAY_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, array, flags, width, precision,
		length, padd, extra_ch));
}

/**
 * write_num - Write a number using the array
 * @ind: Index at which the number starts on the array
 * @array: array
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 * Return: Number of printed chars.
 */

int write_num(int ind, char array[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == ARRAY_SIZE - 2 && array[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == ARRAY_SIZE - 2 && array[ind] == '0')
		array[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		array[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			array[i] = padd;
		array[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				array[--ind] = extra_c;
			return (write(1, &array[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				array[--ind] = extra_c;
			return (write(1, &array[1], i - 1) + write(1, &array[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				array[--padd_start] = extra_c;
			return (write(1, &array[padd_start], i - padd_start) +
				write(1, &array[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		array[--ind] = extra_c;
	return (write(1, &array[ind], length));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the array
 * @array: Array of chars
 * @flags: det flags
 * @width: det width
 * @precision: det precision
 * @size: det size
 * Return: Number of written chars
 */
int write_unsgnd(int is_negative, int ind,
	char array[],
	int flags, int width, int precision, int size)
{
	int length = ARRAY_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == ARRAY_SIZE - 2 && array[ind] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		array[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			array[i] = padd;

		array[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &array[ind], length) + write(1, &array[0], i));
		}
		else
		{
			return (write(1, &array[0], i) + write(1, &array[ind], length));
		}
	}

	return (write(1, &array[ind], length));
}

/**
 * write_pointer - Write a memory address
 * @array: Arrays of chars
 * @ind: Index at which the number starts in array
 * @length: number length
 * @width: det width
 * @flags: det flags
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 * Return: Number of written chars
 */

int write_pointer(char array[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			array[i] = padd;
		array[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			array[--ind] = 'x';
			array[--ind] = '0';
			if (extra_c)
				array[--ind] = extra_c;
			return (write(1, &array[ind], length) + write(1, &array[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			array[--ind] = 'x';
			array[--ind] = '0';
			if (extra_c)
				array[--ind] = extra_c;
			return (write(1, &array[3], i - 3) + write(1, &array[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				array[--padd_start] = extra_c;
			array[1] = '0';
			array[2] = 'x';
			return (write(1, &array[padd_start], i - padd_start) +
				write(1, &array[ind], length - (1 - padd_start) - 2));
		}
	}
	array[--ind] = 'x';
	array[--ind] = '0';
	if (extra_c)
		array[--ind] = extra_c;
	return (write(1, &array[ind], ARRAY_SIZE - ind - 1));
}
