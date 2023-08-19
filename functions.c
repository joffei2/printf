#include "main.h"

/************************* print a character *************************/

/**
 * prnt_char - Prints a character
 * @argt_ls: List a of args
 * @buf: Buffer array that handles print
 * @flags:  Calculates flags
 * @width: Width
 * @precision: Precision specs
 * @size: Size specs
 * Return: Number of characters printed
 */
int prnt_char(va_list argt_ls, char buf[],
	int flags, int width, int precision, int size)
{
	char y = va_arg(argt_ls, int);

	return (handle_write_char(y, buf, flags, width, precision, size));
}
/************************* print a string *************************/
/**
 * prnt_stg - Prints a string
 * @argt_ls: List a of args
 * @buf: Buffer array that handle print
 * @flags:  Calculates flags
 * @width: Width.
 * @precision: Precision specs
 * @size: Size specs
 * Return: Number of character printed
 */
int prnt_stg(va_list argt_ls, char buf[],
	int flags, int width, int precision, int size)
{
	int length = 0, z;
	char *str = va_arg(argt_ls, char *);

	UNUSED(buffer);
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
			for (z = width - length; z > 0; z--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (z = width - length; z > 0; z--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* prints the percentage sign *************************/
/**
 * prnt_percent - Prints the percent symbol
 * @types: List of args
 * @buffer: Buffer array that handle print
 * @flags:  Calculates flags
 * @width: width.
 * @precision: Precision specs
 * @size: Size specs
 * Return: Number of characters to be printed
 */
int prnt_perc(va_list arg_ls, char buf[],
	int flags, int width, int precision, int size)
{
	UNUSED(arg_ls);
	UNUSED(buf);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* prints an integer *************************/
/**
 * prnt_int - Print an integer
 * @arg_ls: List of args
 * @buf: Buffer array that handle print
 * @flags:  Calculates flags
 * @width: width.
 * @precision: Precision specs
 * @size: Size spec
 * Return: Number of character to be printed
 */
int prnt_int(va_list arg_ls, char buf[],
	int flags, int width, int precision, int size)
{
	int o = BUFF_SIZE - 2;
	int is_neg = 0;
	long int y = va_arg(arg_ls, long int);
	unsigned long int numb;

	y = convert_size_number(y, size);

	if (y == 0)
		buf[o--] = '0';

	buf[BUFF_SIZE - 1] = '\0';
	numb = (unsigned long int)y;

	if (y < 0)
	{
		numb = (unsigned long int)((-1) * y);
		is_neg = 1;
	}

	while (numb > 0)
	{
		buf[o--] = (numb % 10) + '0';
		numb /= 10;
	}

	o++;

	return (write_number(is_neg, o, buf, flags, width, precision, size));
}

/************************* print binaries *************************/
/**
 * prnt_bin - Prints unsigned numbers
 * @arg_ls: List of args
 * @buf: Buffer array that handle print
 * @flags:  Calculates flags
 * @width: width.
 * @precision: Precision specs
 * @size: Size spec
 * Return: Numbers of char to be printed.
 */
int prnt_bin(va_list arg_ls, char buf[],
	int flags, int width, int precision, int size)
{
	unsigned int x, y, z, sum;
	unsigned int i[32];
	int count;

	UNUSED(buf);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	x = va_arg(arg_ls, unsigned int);
	y = 2147483648; /* (2 ^ 31) */
	i[0] = x / y;
	for (z = 1; z < 32; z++)
	{
		y /= 2;
		i[z] = (x / y) % 2;
	}
	for (z = 0, sum = 0, count = 0; z < 32; z++)
	{
		sum += i[z];
		if (sum || z == 31)
		{
			char o = '0' + i[z];

			write(1, &o, 1);
			count++;
		}
	}
	return (count);
}
