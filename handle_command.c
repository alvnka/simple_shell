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
	char *full_path, *temp_command;

	for (i = 0; i < 20; i++)
	{
		full_path = find_command_path(parameters[0]);
		if (full_path != NULL)
		{
			found = 1;

			break;
		}
	}
	if (!found)
	{
		printf("%s: command not found\n", command);
		free(full_path);
		exit(0);
	}
	else
	{
		temp_command = malloc(strlen(full_path) + 1);
		if (temp_command == NULL)
		{
			perror("Error");
			exit(0);
		}
		strcpy(temp_command, full_path);
		free(full_path);
		command = temp_command;
		ret = execve(command, parameters, envp);
		if (ret == -1)
		{
			perror("Error");
			free(command);
			exit(0);
		}
	}
	free(command);
}
