#include "main.h"

int _printf(const char *format, ...)
{
    int charct_print = 0;
    va_list arg_ls;

    if (format == NULL)
        return -1;

    va_start(arg_ls, format);

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

            if (*format == 'd' || *format == 'i')
            {
                int numb = va_arg(arg_ls, int);
                char numb_str[12]; //reasonable size for an int in base 10

                int numb_len = sprintf(numb_str, "%d", numb);
                write(1, numb_str, numb_len);
                charct_print += numb_len;
            }
        }
        format++;
    }
    va_end(arg_ls);

    return charct_print;
}
int main()
{
	_printf("%d\n", 2);
	_printf("%i\n", 10);
	return 0;
}
