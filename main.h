#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024


/****************** functions.c ******************/

int prnt_char(va_list argt_ls, char buf[],
	int flags, int width, int precision, int size);
int prnt_stg(va_list argt_ls, char buf[],
	int flags, int width, int precision, int size);
int prnt_perc(va_list arg_ls, char buf[],
	int flags, int width, int precision, int size);
int prnt_int(va_list arg_ls, char buf[],
	int flags, int width, int precision, int size);
int prnt_bin(va_list arg_ls, char buf[],
	int flags, int width, int precision, int size);


/****************** functions1.c ******************/

int prnt_unsigned(va_list arg_ls, char buf[],
	int flags, int width, int precision, int size);
int prnt_octal(va_list arg_ls, char buf[],
	int flags, int width, int precision, int size);
int prnt_hexadecimal(va_list arg_ls, char buf[],
	int flags, int width, int precision, int size);
int prnt_hexa_upper(va_list arg_ls, char buf[],
	int flags, int width, int precision, int size);
int prnt_hexa(va_list arg_ls, char map_to[],char buf[], 
	int flags, char flag_c, int width, int precision, int size)



int _printf(const char *format, ...);
#endif
