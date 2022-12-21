#include "simple_shell.h"
/**
 * path - Function that gets the path from enviorment
 *
 * @env: Enviorment variables
 *
 * Return: a string that contains enviorments, or NULL if failes
 */
char *path(char **env)
{
    int i = 0;
    char *path,  **copy_path, **env_cpy;
    
    env_cpy = envcopy(env);
    
    while (env_cpy[i])
    {
        if (_strncmp(env_cpy[i], "PATH", 4) == 0)
        {
            path = _strdup(env_cpy[i]);
            copy_path = tokenization(path, "=");
            free(path);
            path = _strdup(copy_path[1]);
        }
        i++;
    }
    free_array(copy_path);
    return (path);
}
