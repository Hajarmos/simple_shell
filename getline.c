#include "main.h"

/**
 * readline - reads user input
 * @size: amount of bytes to read
 *
 * Return: String read
*/

char *readline(size_t size)
{
	char *buffer = NULL;
	size_t length;
	int read = 0;

	read = getline(&buffer, &size, stdin);
	if (read == -1)
		write(1, "\n", 1), free(buffer), exit(EXIT_SUCCESS);
	length = _strlen(buffer);
	if (length > 0 && buffer[length - 1] == '\n')
		buffer[length - 1] = '\0';
	return (buffer);
}
