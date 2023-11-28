#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * _printf_char - prints character.
 * @c: char.
 * Return: number of bytes written.
 */
int _printf_char(char c)
{
	return (write(1, &c, 1);
}
/**
 * _printf_string - prints string.
 * @str: string.
 * Return: number of bytes written.
 */
int _printf_string(char *str)
{
	int length = 0;

	if (str == NULL)
		str = "(null)";
	for (length = 0; str[length] != '\0'; length++)
		continue;
	return (write(1, str, length));
}
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
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				count += _printf_char(va_arg(ap, int));
			else if (format[i + 1] == 's')
				count += _printf_string(va_arg(ap, char *));
			else if (format[i + 1] == '%')
				count += write(1, "%", 1);
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
