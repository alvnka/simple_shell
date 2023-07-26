#include "main.h"

/**
 * handle_command_1 - handles the command
 * @command: the command to be handled
 * @parameters: the parameters
 * @envp: the environment variables
 */

void handle_command_1(char *command, char **parameters, char **envp)
{
	char *full_path = find_command_path_1(command);
	int ret;

	if (full_path != NULL)
	{
		parameters[0] = NULL;

		ret = execve(full_path, parameters, envp);

		if (ret == -1)
		{
			perror("Error");
			exit(1);
		}
	}
	else
	{
		exit(1);
		printf("./shell: No such file or directory\n");
	}
}
