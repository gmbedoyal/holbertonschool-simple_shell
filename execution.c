#include "simple_shell.h"

/**
 * execution - executes command given by user
 * @tokens: command line instruccions
 * @env: local environment
 * Return: 0 if command not found, 1 after parent process finishes
*/

int execution(char **tokens,  char **env)
{
	int status;
	pid_t child_pid;
	char *get_path, **cmd, **env_cpy;
	struct stat st;

	env_cpy = envcopy(env); /*create a copy of local environment*/

	if (stat(tokens[0], &st) != 0) /*checks existence of command*/
	{
		get_path = path(env_cpy); /*gets PATH from env*/
		cmd = tokenization(get_path, ":"); /*tokenizes paths on PATH*/
		free(get_path);
		tokens[0] = add_path(tokens, cmd); /*adds command to path*/
		if (stat(tokens[0], &st) != 0) /*checks if command doesn't exists*/
		{
			free_array(cmd);
			free_array(tokens);
			perror("command not found");
			return (0);
		}
	}
	child_pid = fork(); /*as command do exist, fork*/
	if (child_pid == -1)
		perror("Child process failed");
	else if (child_pid == 0)
	{
		if (execve(tokens[0], tokens, env_cpy) == -1) /*if child created OK, execve*/
			perror("./hsh");
	}
	else
		wait(&status); /*wait for child to finish to return to parent*/
	free_array(tokens);
	return (1);
}
