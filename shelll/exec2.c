#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
*main-prototype
*Return: 0
*/
int main(int ac, char **av)
{
	size_t len = 1024;
	char *buffer = NULL;
	char *token;
	int val;
	pid_t pid;

	while (1)
	{
		printf("$ ");
		getline(&buffer, &len, stdin);
		token = strtok(buffer, " ");

		if (token[0] == 'l' && token[1] == 's')
		{
			pid = fork();
			if (pid == 0)
			{
				val = execve("/bin/ls", av, NULL);
				token = strtok(NULL, " ");
			}
			else
			{
			wait(NULL);
			}
		}
		else
		{
			perror("error");
		}
	}
	return (0);
}