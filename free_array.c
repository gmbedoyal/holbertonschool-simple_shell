#include "simple_shell.h"

/**
 * free_array - frees an array
 * @tokens: array to be freed
 * Return: no return
 */
void free_array(char **tokens)
{
	int i = 0;

	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
