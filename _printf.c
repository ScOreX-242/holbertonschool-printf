#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format.
 * @format: character string containing directives.
 *
 * Return: the number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char *str;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			count += putchar(format[i]);
		}
		else
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			if (format[i] == 'c')
				count += putchar(va_arg(args, int));
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
					count += putchar(*str++);
			}
			else if (format[i] == '%')
				count += putchar('%');
			else
			{
				count += putchar('%');
				count += putchar(format[i]);
			}
		}
		i++;
	}
	va_end(args);
	return (count);
}
