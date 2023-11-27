#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
int _printf(const char *format, ...)
{
	char *for_length;
	char *for_malloc;
	va_list ap;
	int i, count = 0, length = 0;

	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == 'c')
		{
			for_malloc = malloc(sizeof(char));
			*for_malloc = va_arg(ap, int);
			write(1, for_malloc, 1);
			free(for_malloc);
		}
		else if (format[i] == 's')
		{
			for_length = va_arg(ap, char *);
			while(for_length[length] != '\0')
				length++;
			//for_malloc = malloc(length * sizeof(char));
			write(1, for_length, length);
		}
	}
	va_end(ap);
	return (count);
}
