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
	size_t size = 1024;
	char *buffer = NULL, **argv, *cmd = NULL;

	if (ac != 1)
		return (-1);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		buffer = readline(size);
		builtin(buffer, cmd, envp);
		argv = splitstr(buffer);
		if (!argv[0])
		{
			free(buffer), free(argv);
			continue;
		}
		if (!_strchr(argv[0], '/'))
		{
			cmd = _which(argv[0], envp);
			if (!cmd)
			{
				free(buffer), free(argv);
				continue;
			}
			argv[0] = cmd;
		}
		if (exec(argv, envp) == -1)
		{
			perror(av[0]);
			free(buffer), free(argv);
			if (cmd)
				free(cmd);
			continue;
		}
		free(buffer), free(argv);
	}
	return (0);
}
