#include "simple_shell.h"
/**
 * tokenization - extract tokens from the getline command
 *
 * @str: String of the command line
 * @delim: Delimiter
 *
 * Return: the array of tokens
 *
 * Description: We first allocate space for the array of tokens. We extract
 * our fits tokenizer and save it in tokenizer. We start a loop that will run while
 * tokenizer have something. Inside we allocate space for the posision inside
 * the index. Then we copy the string from tokenizer into the index. We clean
 * out tokenizer variable and start the process again. After our while our last
 * index is assign as NULL, to mark the end of the array.
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
