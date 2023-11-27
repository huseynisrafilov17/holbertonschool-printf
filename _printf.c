#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...)
{
	char *for_string;
	char for_char;
	va_list ap;
	int i, count = 0, length = 0;

	va_start(ap, format);
	for (i = 1; format[i] != '\0'; i++)
	{
		if (format[i - 1] == '%' && format[i] == 'c')
		{
			for_char = va_arg(ap, int);
			write(1, &for_char, 1);
			count++;
		}
		else if (format[i - 1] == '%' && format[i] == 's')
		{
			for_string = va_arg(ap, char *);
			while(for_string[length] != '\0')
				length++;
			write(1, for_string, length);
			count = count + length;
		}
		else if (format[i - 1] == '%' && format[i] == '%')
		{
			write(1, "%", 1);
			count++;
		}
	}
	va_end(ap);
	return (count);
}
