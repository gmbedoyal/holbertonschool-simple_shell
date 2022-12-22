#include "simple_shell.h"
/**
 * main - main function of shell.
 * Description - on an infinite loop, first we check for interactive mode
 * and print the prompt. Second, we call the signal function to operate
 * "ctrl + c" option. Third, we receive the command line from user and
 * tokenize it. Fourth, we create a copy of the local environment.
 * Fith, we check for env and exit commands. Sixth, we execute the given
 * command. And lastly, we free memory and return 0.
 * @ac: argument count
 * @av: argument vector
 * @env: local environment
 * Return: always return 0.
 */
int main(int ac __attribute__((unused)), char **av,  char **env)
{
	char *buf = NULL, **tokens = NULL, **env_cpy;
	size_t n = 0;
	int i = 0;
	(void)av;

	while (1)
	{
		tokens = NULL;
		buf = NULL;
		n = 0;
		if (isatty(0))
			printf("$ ");

		signal(SIGINT, sigfunc);

		if (getline(&buf, &n, stdin) == EOF)
		{
			free(buf);
			exit(0);
		}
		tokens = tokenization(buf, " \n");
		free(buf);

		env_cpy = envcopy(env);

		if (tokens[0] != NULL)
		{
			if (_strcmp(tokens[0], "env") == 0)
			{
				for (i = 0; env_cpy[i]; i++)
				{
					printf("%s\n", env_cpy[i]);
				}
				free_array(tokens);
				continue;
			}
			if (isexit(tokens) == 1)
				execution(tokens, env);
		}
		else
			free(tokens);
	}
	free_array(tokens);
	free_array(env_cpy);
	free(buf);
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

/**
  * sigfunc - function to operate for ctrl + c
  * @signal: signal received of main
  * Return: no return
  */
void sigfunc(int signal)
{
	(void) signal;
	write(STDIN_FILENO, "\n$ ", 3);
}
