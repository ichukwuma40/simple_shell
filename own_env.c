#include "shell.h"

/**
 * own_env - the function that prints enviroment variables
 * @args: the arguments
 *
 * Return: then 1 on success, or 0 otherwise
 */
int own_env(char **args)
{
	int i = 0;
	(void)(**args);

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (-1);
}
