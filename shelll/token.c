#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *str;
	size_t len = 1024;
	char *delim = " ";
	char *token;

	str = malloc(sizeof(char) * len);

	if (!str)
		return (0);

	getline(&str, &len, stdin);
	token = strtok(str, delim);

	while (token)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}

	free(str);
	return (0);
}
