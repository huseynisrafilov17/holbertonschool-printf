#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...)
{
	char *for_string;
	char for_char;
	va_list ap;
	int i, count = 0, length = 0;

	if (format == NULL)
		exit(60);
	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			for_char = va_arg(ap, int);
			write(1, &for_char, 1);
			count++;
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			for_string = va_arg(ap, char *);
			if (for_string == NULL)
				for_string = "(null)";
			while(for_string[length] != '\0')
				length++;
			write(1, for_string, length);
			count = count + length;
			length = 0;
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			write(1, "%", 1);
			count++;
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
			continue;
		else
		{
			write(1, &(format[i]), 1);
			count++;
		}
	}
	va_end(ap);
	return (count);
}
