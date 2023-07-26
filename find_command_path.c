#include "main.h"

/**
 * find_command_path -  will find the path to the command
 * @command: the command to be found
 * Return: the path to the command
 */

char *find_command_path(char *command)
{
	char *path = getenv("PATH");
	char *dir = strtok(path, ":");
	char *full_path = malloc(sizeof(char) * 1024);

	if (command[0] == '/')
	{
		if (access(command, X_OK) == 0)
		{
			strcpy(full_path, command);
			return (command);
		}
		else
		{
			free(full_path);
			return (NULL);
		}
	}

	else
	{
		while (dir != NULL)
		{
			snprintf(full_path, 1024, "%s/%s", dir, command);
			if (access(full_path, X_OK) == 0)
				return (full_path);
			dir = strtok(NULL, ":");
		}
		free(full_path);
	}
	return (NULL);
}
