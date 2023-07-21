#include "main.h"
#include <stdio.h>

/**
 * builtin - checks for builtin command
 * @cmd: buffer to check
 * @cmd2: command
 * @environ: environment
*/

void builtin(char *cmd, char *cmd2, char **environ)
{
	int i = 0;

	if (_strcmp(cmd, "exit") == 0)
	{
		if (cmd)
			free(cmd);
		if (cmd2)
			free(cmd2);
		exit(EXIT_SUCCESS);
	}
	if (_strcmp(cmd, "env") == 0)
	{
		while (environ[i])
		{
			write(1, environ[i], _strlen(environ[i]));
			i++;
		}
	}
}
