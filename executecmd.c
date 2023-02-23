#include "main.h"
/**
 * execmd - executes a command
 * @argv: array containing the pathname
 * Return: no value
 */



void execmd(char **argv)
{
	char *command = NULL;
	char *main_command = NULL;

	if (argv)
	{
		command = argv[0];
		main_command = get_location(command);

		if (execve(main_command, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
