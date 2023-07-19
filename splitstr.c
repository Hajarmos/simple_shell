#include "main.h"

/**
 * splitstr - splits a string
 * @str: the string
 *
 * Return: an array of each word of the string
 **/

char **splitstr(char *str)
{
	char *token;
	int i = 0;
	char **array = malloc(sizeof(char *) * 1024);

	token = strtok(str, " \t\n");
	while (token)
	{
		array[i] = token;
		i++;
		token = strtok(NULL, " \t\n");
	}
	array[i] = NULL;
	return (array);
}
