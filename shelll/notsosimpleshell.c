#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	size_t len = 1024;
	char *delim = " ", *token;
    int val;
    pid_t pid;

	if (!av)
		return (0);

	getline(av, &len, stdin);
	token = strtok(*av, delim);

	while (token)
	{
		
        printf("%s\n", token);
		token = strtok(NULL, delim);
	}

	return (0);
}
