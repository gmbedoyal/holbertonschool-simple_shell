#include "simple_shell.h"
/**
 * tokenization - extract tokens from the getline command
 * @str: String typed in the command line
 * @delim: Delimiter
 * Return: an array of arrays (each token an array)
 */
char **tokenization(char *str, char *delim)
{
	char *tokenizer = NULL, **tokens = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * 10);
	if (tokens == NULL)
		return (NULL);

	tokenizer = strtok(str, delim);

	while (tokenizer)
	{
		tokens[i] = malloc(sizeof(char) * _strlen(tokenizer) + 1);
		_strcpy(tokens[i], tokenizer);
		i++;
		tokenizer = NULL;
		tokenizer = strtok(NULL, delim);
	}

	tokens[i] = NULL;
	free(tokenizer);
	return (tokens);
}
