#include "simple_shell.h"

/**
 * envcopy - creates a copy of local environment
 * @env: call to the local environment
 * Return: copy of local environment
 *
*/

char **envcopy(char **env)
{
	char **env_cpy;
	int i = 0;

	while (env[i])
		i++;

	env_cpy = calloc(sizeof(char *), i);
	if (env_cpy == NULL)
		return (NULL);

	for (i = 0; env[i]; i++)
		env_cpy[i] = strdup(env[i]);

	env_cpy[i] = NULL;

	return (env_cpy);
}
