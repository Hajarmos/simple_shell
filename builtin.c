#include "main.h"
#include <stdio.h>
/**
 * is_number - check the string is number
 * @s: string
 * Return: 1if is number or 0 if not
 */

int is_number(char *s)
{
	int i = 0;

	while (*(s + i))
	{
		if (*(s + i) <= 57 && *(s + i) >= 48)
			i++;
		else
			return (0);
	}
	return (1);
}
/**
 * exit_error - print exit error
 * @progname: program name
 * @str: string
 *
 * Return: nothing
 */
void exit_error(char *progname, char *str)
{
	write(1, progname, _strlen(progname));
	write(1, ": exit: ", 8);
	if (is_number(str))
	{
		write(1, "too many arguments\n", 19);
		return;
	}
	write(1, str, _strlen(str));
	write(1, ": numeric argument required\n", 28);
}
/**
 * builtin - checks for builtin command
 * @cmd: buffer to check
 * @environ: environment
 * @progname: programme name
 * Return: 1 for exit, 0 for env, -1 for neither
*/

int builtin(char **cmd, char **environ, char *progname)
{
	int ex, i = 0;

	if (_strcmp(cmd[0], "exit") == 0)
	{
		if (cmd[1])
		{
			if (is_number(cmd[1]))
			{
				if (!cmd[2])
				{
					ex = _atoi(cmd[1]);
					return (ex);
				}
				exit_error(progname, cmd[1]);
				return (-3);
			}
			else
			{
				exit_error(progname, cmd[1]);
				return (2);
			}
		}
		return (0);
	}
	else if (_strcmp(cmd[0], "env") == 0)
	{
		if (!cmd[1])
		{
			while (environ[i])
				write(1, environ[i], _strlen(environ[i])), write(1, "\n", 1), i++;
		}
		else
		{
			write(1, cmd[0], _strlen(cmd[0])), write(1, ": '", 3);
			write(1, cmd[1], _strlen(cmd[1]));
			write(1, "’: No such file or directory\n", 31);
		}
		return (-2);
	}
	return (-1);
}
