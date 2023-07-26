#include "main.h"

/**
 * handle_command - handles the command
 * @command: the command to be handled
 * @parameters: the parameters
 * @envp: the environment variables
 */

void handle_command(char *command, char **parameters, char **envp)
{
	int i, ret, found = 0;

	for (i = 0; i < 20; i++)
	{
		strcpy(command, find_command_path(parameters[0]));
		if (command != NULL)
		{
			found = 1;

			break;
		}
	}
	if (!found)
	{
		printf("%s: command not found\n", command);
		exit(0);
	}
	else
	{
		ret = execve(command, parameters, envp);
		if (ret == -1)
		{
			perror("Error");
			exit(0);
		}
	}
	free(command);
}
