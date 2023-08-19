# include "main.h"

int _printf(const char *format, ...)
{
	int charct_print = 0;
	va_list list_of_arg;

	if (format == NULL)
		return -1;

	va_start(arg_ls, formal);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			charct_print++;
		}

		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				charct_print++;
			}
			else if (*format == 'c')
			{
				char c = var_arg(arg_ls, int);
				write(1, &c, 1);
				charct_print++;
			}
			else if (*format == 's')
			{
				char *strg = va_arg(arg_ls, char*);
				int str_len = 0;

				while (strg[str_len] != '\0')
					str_len++;

				write(1, strg, str_len);
				charct_print += str_len;
			}
		}
		format++;
	}
	va_end(arg_ls);

	return charct_print;
}
