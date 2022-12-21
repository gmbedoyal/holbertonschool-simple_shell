#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *_getenv(const char *name)
{
	 unsigned int i = 0;
	 size_t j = 0;
	 extern char **environ;
	 char **env_cpy;

	 while (environ[i])
	 i++;

	 while(name[j])
	j++;
	j = j - 1;

	env_cpy = malloc(sizeof(char *) * i);
	for (i = 0; environ[i]; i++)
		env_cpy[i] = strdup(environ[i]);
	env_cpy[i] = NULL;

	i = 0;
	while (env_cpy[i])
	{
		if (strncmp(env_cpy[i], name, j) == 0)
		{
			printf("%s\n", env_cpy[i]);
			break;
		}
		else
		i++;
	}
	return(0);
}

int main()
{
	size_t n = 1;
	unsigned int i = 0;
	char *name = NULL;
	
	 printf("Insert environment variable: ");
	 getline(&name, &n, stdin);
	 _getenv(name);
return(0);
}
