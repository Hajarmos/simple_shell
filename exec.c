#include "main.h"

/**
 * exec - executes a command
 * @argv: argument vector
 * @envp: environment
 *
 * Return: 0 (Success), -1 (Failure)
*/


int exec(char **argv, char **envp)
{
	int status;
	pid_t pid;

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
			return (-1);
		}
	}
	return (0);
}
