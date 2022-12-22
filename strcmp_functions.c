#include "simple_shell.h"
/**
 * _strcmp - compare two strings, position by position
 * @str1: source string
 * @str2: string to be compared againt str1
 * Return: 0 if strings arre equal, another value if not equal
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return (0);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/**
 * _strncmp - Compares two strings up to n size
 * @str1: source string
 * @str2: string to be compared againt str1
 * @n: number of positions to compare starting 0
 * Return: 0 if strings arre equal, another value if not equal
*/
int _strncmp(char *str2,  char *str1, size_t n)
{
	while (n && *str2 && (*str2 == *str1))
	{
		++str2;
		++str1;
		--n;
	}

	if (n == 0)
		return (0);
	else
		return (*(unsigned char *)str2 - *(unsigned char *)str1);
}
