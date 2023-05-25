#include "main.h"

/**
 * print_number - prints an integer with _putchar_err
 * @n: our integer
 *
 * Return: void
 */
void print_number(int n)
{
	int d = 1000000000, l = 0;

	if (n < 0 && n != INT_MIN)
	{
		_putchar_err('-');
		n = -n;
	}

	while (l == 0 && n > 0)
	{
		l = (n / d) % 10;
		d /= 10;
	}

	while (d > 0 && n > 0)
	{
		_putchar_err(l + '0');
		l = (n / d) % 10;
		d /= 10;
	}

	if (n != INT_MIN)
		_putchar_err(n % 10 + '0');

	if (n == INT_MIN)
	{
		_putchar_err('-');
		print_number((INT_MIN / 100) * -1);
		print_number((INT_MIN % 100) * -1);
	}
}
