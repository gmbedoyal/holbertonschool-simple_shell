#include "simple_shell.h"
/**
 * _strcpy - Copies the string pointed to by src
 * including the terminating null byte(\0), to the string
 * pointed to by dest.
 * @dest: destination
 * @src: source
 * Return: dest string
 */
char *_strcpy(char *dest, char *src)
{
	int copy;

	copy = 0;

	while (src[copy] != '\0')
	{
		dest[copy] = src[copy];
		copy++;
	}
	dest[copy] = '\0';

	return (dest);
}

/**
 * _strcat - Concatenates the src to the dest string,
 * overwriting the termination null byte at the end of dest,
 * and then adds a termination null byte.
 * @dest: destination
 * @src: source
 * Return: dest string
 */
char *_strcat(char *dest, char *src)
{
	int move, original;

	original = 0;
	move = 0;

	while (dest[original] != '\0')
		original++;

	dest[original] = '/';

	original++;

	while (src[move] != '\0')
	{
		dest[original] = src[move];
		original++;
		move++;
	}
	dest[original] = '\0';
	return (dest);
}

/**
 * _strlen - Returns the lenght of a string
 * @s: string to be measured
 * Return: the lenght of the string
 */
int _strlen(char *s)
{
	int lenght;

	while (s[lenght] != '\0')
		lenght++;

	return (lenght);
}

/**
 * _strdup - Duplicates a string
 * @s: string to duplicate
 * Return: Copy of given string
*/
char *_strdup(char *s)
{
	char *ptr;
	int i, len = 0;

	if (s == NULL)
		return (NULL);

	len = _strlen(s);

	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		ptr[i] = s[i];

	ptr[i] = '\0';

	return (ptr);
}
