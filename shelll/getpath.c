#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main ()
{
	 unsigned int i = 0;
	 extern char **environ;
	 char **env_cpy;
	 char *path = "PATH";
	 char *token;

	 while (environ[i])
	 i++;

	env_cpy = malloc(sizeof(char *) * i);
	for (i = 0; environ[i]; i++)
		env_cpy[i] = strdup(environ[i]);
	env_cpy[i] = NULL;

	i = 0;
	while (env_cpy[i])
	{
		if (strncmp(env_cpy[i], path, 4) == 0)
		{
			token = strtok(env_cpy[i],"=");
			while (token)
			{
				token = strtok(NULL, ":");
				printf("%s\n", token);
			}
		}
		else
		i++;
	}
	return(0);
}
