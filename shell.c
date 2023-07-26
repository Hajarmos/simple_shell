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

int main(int ac, char **av, char **envp)
{
	size_t size = 1024;
	char *buffer = NULL, **argv;
	unsigned int i = 0;
	int built, exe;

	if (ac != 1)
		return (-1);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		buffer = readline(size);
		argv = splitstr(buffer);
		i++;
		if (!argv[0])
		{
			free(buffer), free(argv);
			continue;
		}
		built = builtin(argv, envp, av[0]);
		if (built != -1)
		{
			free(buffer), free(argv);
			if (built > -1)
				exit(built);
			continue;
		}
		exe = exec(argv, av[0], envp, i);
		if (exe != 0)
		{
			free(buffer), free(argv);
			if (exe == -1)
				continue;
			else
				exit(EXIT_SUCCESS);
		}
		free(buffer), free(argv);
	}
	return (0);
}
