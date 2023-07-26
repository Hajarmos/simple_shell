#include "main.h"
/**
 * length_number - return the length of number
 * @x: the number
 * Return: int
 */
int length_number(int x)
{
	int len = 0;

	while (x / 10)
	{
		len++;
		x /= 10;
	}
	return (len);
}

/**
 * divisible_number - Divisible number to restore the number on the far left
 * @x: The number of times 10 is multiplied by itself
 * Return: int
 */
int divisible_number(int x)
{
	if (x > 1)
		return (10 * divisible_number(--x));
	if (x == 0)
		return (1);
	return (10);
}
/**
 * print_integer - prints a number
 * @n: number
 * Return: nothing
 */
void print_integer(unsigned int n)
{
	int len, d, x;
	char c;

	do {
		len = length_number(n);
		d = divisible_number(len);
		x = n / d;
		c = x + '0';
		write(1, &c, 1);
		if ((n % 10) == 0)
		{
			c = 0 + '0';
			write(1, &c, 1);
		}
		n %= d;
	} while (n && d != 1);
}
