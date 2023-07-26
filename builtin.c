#include "main.h"
#include <stdio.h>

/**
 * builtin - checks for builtin command
 * @cmd: buffer to check
 * @environ: environment
 * Return: 1 for exit, 0 for env, -1 for neither
*/

int builtin(char **cmd, char **environ)
{
	int ex, i = 0;

	if (_strcmp(cmd[0], "exit") == 0)
	{
		if (cmd[1] != NULL)
		{
			ex = _atoi(cmd[1]);
			return (ex);
		}
		return (0);
	}
	if (_strcmp(cmd[0], "env") == 0)
	{
		if (!cmd[1])
		{
			while (environ[i])
			{
				write(1, environ[i], _strlen(environ[i]));
				i++;
			}
		}
		perror("env");
		return (-2);
	}
	return (-1);
}
