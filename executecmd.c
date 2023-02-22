#include "main.h"
/**
 * execmd - executes a command
 * @argv: array containing the pathname
 * Return: no value
 */



void execmd(char **argv)
{
	char *command = NULL;

	if (argv)
	{
		command = argv[0];

		if (execve(command, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
