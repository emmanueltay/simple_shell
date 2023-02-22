#include "main.h"

/**
 * main - The main entry
 * @ac: number of command line arguments
 * @argv: pointer to array of command line arguments
 * Return: 0 (Successful)
 */

int main(int ac __attribute__((unused)), char **argv)
{
	char *prompt = "ShellCommand$";
	char *lineptr = NULL;/*pointer that stores the input*/
	size_t n = 0;/*stores allocated size in bytes*/
	ssize_t nchars_read;
	int num_of_tokens = 0;
	char *token;
	int i;
	char *lineptr_copy = NULL;
	const char *delim = " \n";

	while (1)
	{
		/*printing the prompt*/
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);/*accepting input from stdin*/
		if (nchars_read == -1)
		{
			printf("Exiting the shell....\n");
			return (-1);
		}
		/* allocating memory for the return value of lineptr*/
		lineptr_copy = malloc(sizeof(char) * nchars_read);
		if (lineptr_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}

		strcpy(lineptr_copy, lineptr);/*copy of lineptr to lineptr_copy*/

		/* split the lineptr into an array of words */
		token = strtok(lineptr, delim);

		/*counting the number of tokens*/
		while (token != NULL)
		{
			num_of_tokens++;
			token = strtok(NULL, delim);
		}
		num_of_tokens++;
		/*allocating memory for the tokens*/
		argv = malloc(sizeof(char *) * num_of_tokens);

		/*storing each token in an array*/
		token = strtok(lineptr_copy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;


		/*executing the command*/
		execmd(argv);
	
	}
	free(lineptr);
	free(lineptr_copy);
	return (0);
}
