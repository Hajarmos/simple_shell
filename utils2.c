#include "main.h"

/**
 * _strcat - concatenates two strings
 *@dest: char
 *@src: char
 * Return: resulting string
 */

char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (p);

}
#include "main.h"
/**
 * _strcpy - copy the string pointed to by src to dest
 * @dest: char to check
 * @src: char to check
 * Return: 0 is success
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
