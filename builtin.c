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
	else if (_strcmp(cmd[0], "env") == 0)
	{
		if (!cmd[1])
		{
			while (environ[i])
			{
				write(1, environ[i], _strlen(environ[i]));
				write(1, "\n", 1);
				i++;
			}
		}
		else
		{
			write(1, cmd[0], _strlen(cmd[0]));
			write(1, ": '", 3);
			write(1, cmd[1], _strlen(cmd[1]));
			write(1, "’: No such file or directory\n", 31);
		}
		return (-2);
	}
	return (-1);
}
