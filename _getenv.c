#include "main.h"

/**
 * _getenv - get value of name in environ
 * @name: name of value
 * @environ: environment
 *
 * Return: pointer to value of name
 */

char *_getenv(const char *name, char **environ)
{
	char *key;
	int i = 0;

	while(environ[i])
	{
		key = strtok(environ[i], "=");
		if (strcmp(key, name) == 0)
			return (strtok(NULL, "\n"));
		i++;
	}
	return (NULL);
}
