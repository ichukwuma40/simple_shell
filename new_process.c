#include "shell.h"

/**
 * new_process - To create a new process
 * @args: the array of strings that contains the command and its flags
 *
 * Return: 1 if success, if not success 0 otherwise.
 */
int new_process(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid ==  0)
	{
		/* the child process */
		if (execvp(args[0], args) == -1)
		{
			perror("error in new_process: child process");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* the error forking */
		perror("error in new_process: forking");
	}
	else
	{
		/*This is the parent process */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}
