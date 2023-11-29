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
		count += _printf_char(b / i + 48);
		b = b % i;
	}

	return (count);
}
/**
 * _printf_binary - prints binary.
 * @a: int.
 * Return: count.
 */
int _printf_binary(long int a)
{
	int count = 0;

	for (; a != 0; a /= 2)
		count += _printf_char(a % 2 + 48);
	return (count);
}
