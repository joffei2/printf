#include "main.h"

/************************* prints unsigned numbers *************************/
/**
 * prnt_unsigned - Prints unsigned numbers
 * @arg_ls: List of args
 * @buf: Buffer array that handles print
 * @flags:  Calculates flags
 * @width: width
 * @precision: Precision specs
 * @size: Size spec
 * Return: Number of character to be printed.
 */
int prnt_unsigned(va_list arg_ls, char buf[],
	int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(arg_ls, unsigned long int);

	numb = conv_size_unsigned(numb, size);

	if (numb == 0)
		buf[x--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buf[x--] = (numb % 10) + '0';
		numb /= 10;
	}

	x++;

	return (write_unsigned(0, x, buf, flags, width, precision, size));
}

/************* print octal unsigned numbers  ****************/
/**
 * prnt_octal - Prints octal unsigned numbers
 * @arg_ls: List of args
 * @buf: Buffer array that handle print
 * @flags:  Calculates flags
 * @width: width
 * @precision: Precision specs
 * @size: Size spec
 * Return: Number of character to be printed
 */
int prnt_octal(va_list arg_ls, char buf[],
	int flags, int width, int precision, int size)
{

	int z = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(arg_ls, unsigned long int);
	unsigned long int int_num = numb;

	UNUSED(width);

	numb = conv_size_unsigned(num, size);

	if (numb == 0)
		buf[z--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buf[z--] = (numb % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && int_num != 0)
		buf[z--] = '0';

	z++;

	return (write_unsigned(0, z, buf, flags, width, precision, size));
}

/************** prints hexadecimal unsigned numbers **************/
/**
 * prnt_hexadecimal - Prints hexadecimal unsigned nubers
 * @arg_ls: List of args
 * @buf: Buffer array that handle print
 * @flags:  Calculates flags
 * @width: width
 * @precision: Precision specs
 * @size: Size spec
 * Return: Number of characters to be printed
 */
int prnt_hexadecimal(va_list arg_ls, char buf[],
	int flags, int width, int precision, int size)
{
	return (prnt_hexa(types, "0123456789abcdef", buf,
		flags, 'x', width, precision, size));
}

/************* prints upper hexadecimal numbers **************/
/**
 * prnt_hexa_upper - Prints upper hexadecimal numbers
 * @arg_ls: List of args
 * @buf: Buffer array that handle print
 * @flags:  Calculates flags
 * @width: width
 * @precision: Precision specs
 * @size: Size spec
 * Return: Number of chars to be printed
 */
int prnt_hexa_upper(va_list arg_ls, char buf[],
	int flags, int width, int precision, int size)
{
	return (prnt_hexa(arg_ls, "0123456789ABCDEF", buf,
		flags, 'X', width, precision, size));
}

/************** prints hexagonal upper or lower numbers **************/
/**
 * prnt_hexa - prints hexagonal upper or lower numbers
 * @arg_ls: List of args
 * @map_to: Array ofvalues that map the number to
 * @buf: Buffer array that handle print
 * @flags:  Calculates flags
 * @flag_c: Calculates  flags
 * @width:  width
 * @precision: Precision specs
 * @size: Size spec
 * Return: Number of chars to be printed
 */
int prnt_hexa(va_list arg_ls, char map_to[], char buf[],
	int flags, char flag_c, int width, int precision, int size)
{
	int z = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(arg_ls, unsigned long int);
	unsigned long int int_num = numb;

	UNUSED(width);

	numb = conv_size_unsigned(numb, size);

	if (numb == 0)
		buf[z--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buf[z--] = map_to[numb % 16];
		numb /= 16;
	}

	if (flags & F_HASH && int_num != 0)
	{
		buf[z--] = flag_ch;
		buf[z--] = '0';
	}

	z++;

	return (write_unsigned(0, z, buf, flags, width, precision, size));
}
