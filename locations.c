#include "main.h"

/*
 * get_location - gets the location of enviroment variables
 * @command: the passed command
 * Return: pointer to the variable path
 */

char *get_location(char *command)
{
	char *path, *path_copy;
	int command_length;
	char *path_token;
	int directory_length;
	char *file_path;
	struct stat buffer;

	path = getenv("PATH");/*getting the environment variable*/
	if (path)
	{
		path_copy = strdup(path);/*making a copy of the environment variable*/
		command_length = strlen(command);/*finding the length of the command*/
		/*tokenizing the path variable to get all the directories*/
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			directory_length = strlen(path_token);/*getting the length of the directory*/

			/*allocating memory to store comand name and directory name*/
			file_path = malloc(command_length + directory_length + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
