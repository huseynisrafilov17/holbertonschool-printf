#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * _printf - Function printf.
 * @format: String.
 * Return: Count.
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i, count = 0;

	va_start(ap, format);
	for (i = 0; format != NULL && format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			if (format[i + 1] == 'c')
				count += _printf_char(va_arg(ap, int));
			else if (format[i + 1] == 's')
				count += _printf_string(va_arg(ap, char *));
			else if (format[i + 1] == '%')
				count += _printf_char('%');
			else if (format[i + 1] == 'i' || format[i + 1] == 'd')
				count += _printf_int(va_arg(ap, int));
			else if (format[i + 1] == 'b')
				count += _printf_binary(va_arg(ap, int));
			else
			{
				count += _printf_char(format[i]);
				count += _printf_char(format[i + 1]);
			}
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
			continue;
		else
			count += _printf_char(format[i]);
	}
	va_end(ap);
	if (count == 0)
		exit(60);
	return (count);
}
