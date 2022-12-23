#include "simple_shell.h"

/**
 * is_env - check if command env is typed in
 * @tokens: array of tokens where command is stored
 * @env_cpy: copy of environment
 * Return: 1 if the word is not exit, or 0 if it's exit
 */

int is_env(char **tokens, char **env_cpy)
{
int i;
if (_strcmp(tokens[0], "env") == 0)
{
	for (i = 0; env_cpy[i]; i++)
		printf("%s\n", env_cpy[i]);
}
if (isexit(tokens) == 1)
	execution(tokens, env_cpy);
return (0);
}

/**
 * isexit - check if command exit is typed in
 * @tokens: array of tokens where command is stored
 * Return: 1 if the word is not exit, or 0 if it's exit
 */

int isexit(char **tokens)
{
	if (_strcmp(tokens[0], "exit") == 0)
	{
		free_array(tokens);
		exit(0);
	}
	return (1);
}
