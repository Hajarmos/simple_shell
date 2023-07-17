#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#define _GNU_SOURCE

/**
 * free_arr - frees a 2 dimensional grid previously created
 * @array: array
 * Return: nothing
 */
void free_arr(char **array)
{
        int i, len = 0;

        while (array[len])
                len++;
        for (i = 0; i < len; i++)
                free(array[i]);
        i++;
        free(array);
}
/**
 * main - simple shell
 * @ac: arg number
 * @av: arg array
 * @envp: current environment
 * Return: it's a loop
 */

int main(int ac, char **av __attribute__((unused)), char **envp)
{
	int read = 0, status;
	size_t size = 1024;
	pid_t pid;
	char *buffer, **argv, *cmd;

	if (ac != 1)
		return (-1);
	while (1)
	{
		buffer = malloc(sizeof(char) * 1024);
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		read = getline(&buffer, &size, stdin);
		if (read == -1)
			write(1, "\n", 1), free(buffer), exit(EXIT_SUCCESS);
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
			else
				argv[0] = cmd;
		}
		pid = fork();
		if (pid != 0)
		{
			if (pid == -1)
				perror("Error");
			wait(&status);
		}
		if (!pid)
		{
			if (execve(argv[0], argv, envp) == -1)
			{
				perror("./shell");
				free(buffer), free(argv);
				continue;
			}
		}
		free(buffer), free(argv);
		if (!isatty(STDIN_FILENO))
			exit(EXIT_SUCCESS);
	}
	return (0);
}
