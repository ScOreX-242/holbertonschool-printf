#include "main.h"

/**
 * print_char - prints char
 * @args: arguments
 *
 * Return: On success 1.
 * On error, -1 is returned.
 */
int print_char(va_list *args)
{
	char c = va_arg(*args, int);

	write(1, &c, 1);
	return (1);
}
