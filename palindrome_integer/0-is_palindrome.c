#include "palindrome.h"

/**
 * is_palindrome - Checking if a integer is a palindrome.
 * @n: checked number
 *
 * Return: an integer
 */
int is_palindrome(unsigned long n)
{
	unsigned long original_number = n;
	unsigned long reversed_number = 0;

	while (n > 0)
	{
		reversed_number = reversed_number * 10 + (n % 10);
		n /= 10;
	}

	return (original_number == reversed_number);
}