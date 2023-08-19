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

            if (*format == '%')
            {
                write(1, format, 1);
                charct_print++;
            }
            else if (*format == 'c')
            {
                char c = va_arg(arg_ls, int);
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
            else if (*format == 'b')
            {
                unsigned int num = va_arg(arg_ls, unsigned int);
                char binary_str[33]; // Assuming 32-bit unsigned int

                // Convert the unsigned int to binary
                for (int i = 31; i >= 0; i--)
                {
                    binary_str[31 - i] = (num & (1 << i)) ? '1' : '0';
                }
                binary_str[32] = '\0';

                write(1, binary_str, 32); // Assuming 32-bit binary output
                charct_print += 32;
            }
        }
        format++;
    }
    va_end(arg_ls);

    return charct_print;
}
int main()
{
    unsigned int num1 = 42;
    unsigned int num2 = 255;
    
    _printf("Binary representation of 42: %b\n", num1);
    _printf("Binary representation of 255: %b\n", num2);
    
    return 0;
}
