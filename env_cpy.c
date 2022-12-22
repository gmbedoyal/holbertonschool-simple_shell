#include "simple_shell.h"

/**
 * 
 * 
 * 
 * 
*/

char **envcopy(char** env)
{
    char **env_cpy;
    int i = 0;

    while (env[i])
        i++;

    env_cpy = malloc(sizeof(char *) * i);
    if (env_cpy == NULL)
        return (NULL);
        
    for (i = 0; env[i]; i++)
        env_cpy[i] = strdup(env[i]);
	env_cpy[i] = NULL;

    return(env_cpy);
}