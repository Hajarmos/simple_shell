#include "main.h"
#include <stdio.h>

void builtin(char *cmd, char *cmd2, char **environ __attribute__((unused)))
{
	if (_strcmp(cmd, "exit") == 0)
	{
		if (cmd)
			free(cmd);
		if (cmd2)
			free(cmd2);
		exit(EXIT_SUCCESS);
	}
}