#include "main.h"

/**
 * print_number - prints an integer
 * @n: The integer to print
 *
 * Return: The number of characters printed
 */
int print_number(int n)
{
	unsigned int num;
	int count = 0;
	unsigned int div = 1;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	while (num / div > 9)
		div *= 10;

	while (div != 0)
	{
		count += _putchar((num / div) + '0');
		num %= div;
		div /= 10;
	}

	return (count);
}
