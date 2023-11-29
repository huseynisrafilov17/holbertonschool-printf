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
	return (write(1, &c, 1));
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
 * _printf_int - prints int.
 * @a: integer.
 * Return: Count.
 */
int _printf_int(int a)
{
	unsigned int b, count = 0, i;

	if (a < 0)
	{
		count += _printf_char('-');
		b = -1 * a;
	}
	else
		b = a;
	for (i = 1; (b / i) / 10 > 0; i *= 10)
		continue;
	for (; i > 0; i /= 10)
	{
		count += _printf_char(b / 10 + 48);
		b = b % 10;
	}

	return (count);
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
