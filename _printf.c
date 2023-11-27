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
	char *for_string;
	char for_char;
	va_list ap;
	int i, count = 0, length = 0;

	va_start(ap, format);
	for (i = 0; format != NULL && format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			for_char = va_arg(ap, int);
			count += write(1, &for_char, 1);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			for_string = va_arg(ap, char *);
			if (for_string == NULL)
				for_string = "(null)";
			for (length = 0; for_string[length] != '\0'; length++)
				continue;
			count += write(1, for_string, length);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			count += write(1, "%", 1);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
			continue;
		else
			count += write(1, &(format[i]), 1);
	}
	va_end(ap);
	if (count == 0)
		exit(60);
	return (count);
}
