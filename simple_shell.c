#include "main.h"

/**
 * main - shell entry point
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment variables
 * Return: 0 on success
 */
int main(int argc, char *argv[], char *envp[])
{
	char cmd[100], command[100], *parameters[20];
	int status;


	(void)argc, (void)argv;

	while (1)
	{
		type_prompt();
		read_command(cmd, parameters);
		if (check_exit(cmd))
			break;
		if (fork() != 0)
		{
			wait(&status);
		}
		else
		{
			handle_command(command, parameters, envp);
		}
	}
	return (0);
}
