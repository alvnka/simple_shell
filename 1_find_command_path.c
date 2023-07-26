#include "main.h"

/**
 * find_command_path_1 -  will find the path to the command
 * @command: the command to be found
 * Return: the path to the command
 */

char *find_command_path_1(char *command)
{

	if (command[0] == '/')
	{
		if (access(command, X_OK) == 0)
		{
			return (command);
		}
		else
		{
			return (NULL);
		}
	}
	else
	{
		printf("./shell: No such file or directory\n");
		return (NULL);
	}
}
