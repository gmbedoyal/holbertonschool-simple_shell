#include "simple_shell.h"
/**
 * add_path - Concatenates the path with the command given by user
 * @tokens: command given by user
 * @paths: current path
 * Return: the path concatenated in position 0 of the array.
 */
char *add_path(char **tokens, char **paths)
{
	char *cmd;
	int i = 0;
	struct stat st;

	while (paths[i])
	{
		cmd = _strcat(paths[i], tokens[0]);
		if (stat(cmd, &st) == 0)
		{
			tokens[0] = cmd;
			break;
		}
		i++;
	}

	return (tokens[0]);
}
