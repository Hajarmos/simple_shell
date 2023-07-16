#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#define _GNU_SOURCE

/**
 * main - simple shell
 * @ac: arg number
 * @av: arg array
 * @envp: current environment
 * Return: it's a loop
 */

int main(int ac, char **av __attribute__((unused)), char **envp)
{
	size_t read = 0, size = 1024;
	pid_t pid;
	/*int line = 1;*/
	char *buffer = NULL;
	char **argv;

	if (ac != 1)
		return (-1);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		read = getline(&buffer, &size, stdin);
		if (read == (size_t)-1)
			write(1, "\n", 1), exit(EXIT_SUCCESS);
		if (read > 0 && buffer[read - 1] == '\n')
			buffer[read - 1] = '\0';
		argv = malloc(2), argv[0] = _strdup(buffer), argv[1] = NULL;
		pid = fork();
		if (pid != 0)
		{
			if (pid == -1)
			{
				perror("Error");
			}
			wait(NULL);
		}
		if (!pid)
		{
			if (execve(argv[0], argv, envp) == -1)
			{
				perror("./hsh");
				continue;
			}
		}
		free(buffer), free(argv);
		if (!isatty(STDIN_FILENO))
			exit(0);
	}
	return (0);
}
