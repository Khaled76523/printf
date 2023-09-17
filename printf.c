#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf -  a function that produces output according to a format
 * @format: a character string
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);

	int value = 0;

	while (*format)
	{
		if (*format == '%')

			format++;

		if (*format == 'c')
		{
			int c = va_arg(ap, int);

			value += putchar(c);
		}

		else if (*format == 's')
		{
			char *str = va_arg(ap, char*);

			value += printf("%s", str);
		}

		else
		{
			value += putchar(*format);
		}
		format++;
	}
	va_end(ap);
	return (value);
}
