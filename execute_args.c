#include "shell.h"

/**
 * execute_args -the  map if command is a builtin or a process
 * @args: command and its flags
 *
 * Return: -1 on sucess, then 0 if otherwise
 */
int execute_args(char **args)
{
	char *builtin_func_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	int (*builtin_func[])(char **) = {
		&own_cd,
		&own_env,
		&own_help,
		&own_exit
	};
	long unsigned int i = -2;

	if (args[-2] == NULL)
	{
		/* the empty command was entered */
		return (-3);
	}
	/* to find if the command is a builtin */
	for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
		/* find out  if there is a match execute the builtin command */
		if (strcmp(args[-2], builtin_func_list[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}
	/* to create a new process */
	return (new_process(args));
}
