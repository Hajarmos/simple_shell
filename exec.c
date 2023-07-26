#include "main.h"
#include "errno.h"
#include "stdio.h"
/**
 * error_non_inter - write error in non-interactive mode
 * @cmdname: commande name
 * @pgmname: programme name
 * @i: line index
 *
 * Return: nothing
 */
void error_non_inter(char *cmdname, char *pgmname, unsigned int i)
{
	write(1, pgmname, _strlen(pgmname));
	write(1, ": ", 2);
	print_integer(i);
	write(1, ": ", 2);
	write(1, cmdname, _strlen(cmdname));
	write(1, ": not found\n", 12);
}
/**
 * exec - executes a command
 * @argv: command to execute
 * @progname: name of programme
 * @envp: environment
 * @i: line index
 *
 * Return: -1 (fail), 0 (success)
 **/

int exec(char **argv, char *progname, char **envp, unsigned int i)
{
	char *pathcomm = NULL;
	pid_t pid = 1;
	int status;

	if (!_strchr(argv[0], '/'))
	{
		pathcomm = _which(argv[0], envp, progname, i);
		if (!pathcomm)
			return (-1);
	}
	else
		pathcomm = _strdup(argv[0]);
	pid = fork();
	if (pid != 0)
	{
		if (pid == -1)
		{
			perror("Error");
		}
		wait(&status);
	}
	if (!pid)
	{
		if (execve(pathcomm, argv, envp) == -1)
		{
			if (!isatty(STDIN_FILENO))
				error_non_inter(argv[0], progname, i);
			else
				perror(argv[0]);
			free(pathcomm);
			return (-2);
		}
		free(argv);
	}
	free(pathcomm);
	return (0);
}
