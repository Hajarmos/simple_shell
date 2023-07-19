#include "main.h"

/**
 * _which - find path of command
 * @cmdname: name of command
 * @envp: environment
 *
 * Return: path of command if exist
 */

char *_which(char *cmdname, char **envp)
{
	char *path = _getenv("PATH", envp), *token, *cmdpath;
	struct stat st;

	token = strtok(path, ":");
	while (token)
	{
		cmdpath = malloc(_strlen(token) + _strlen(cmdname) + 2);
		if (!cmdpath)
			perror("malloc"), exit(EXIT_FAILURE);
		_strcpy(cmdpath, token);
		_strcat(cmdpath, "/");
		_strcat(cmdpath, cmdname);
		if (stat(cmdpath, &st) == 0)
		{
			free(path);
			return (cmdpath);
		}
		free(cmdpath);
		token = strtok(NULL, ":");
	}
	free(path);
	write(1, cmdname, _strlen(cmdname));
	write(1, ": command not found\n", 20);
	return (NULL);
}
