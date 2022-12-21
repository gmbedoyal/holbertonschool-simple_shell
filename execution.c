#include "simple_shell.h"

int execution(char **tokens,  char **env)
{
    int status, i, j = 0;
    pid_t child_pid;
    char *path_tok, **cmd, **env_cpy;
    struct stat buffer;

    env_cpy = envcopy(env);

    if (stat(tokens[0], &buffer) != 0)
    {
        path_tok = path(env_cpy);
        cmd = tokenization(path_tok, ":");
        free(path_tok);
        tokens[0] = add_path(tokens, cmd);
        if (stat(tokens[0], &buffer) != 0)
        {
            free_array(cmd);
            free_array(tokens);
            perror("cmd not found");
            return (0);
        }
    }
    child_pid = fork();
    if (child_pid == -1)
        perror("Child process failed");
    else if (child_pid == 0)
    {
        if (execve(tokens[0], tokens, env_cpy) == -1)
            perror("./hsh");
    }
    else
        wait(&status);
    free_array(tokens);
    return (1);
}
