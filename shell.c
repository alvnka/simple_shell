#include "main.h"

/**
 * main - shell entry point
 * Return: 0 on success
 */
int main(void)
{
	char cmd[100], *parameters[20];
	int status;

	while (1)
	{
		type_prompt();
		read_command_1(cmd);
		if (check_exit(cmd))
			break;
		if (fork() != 0)
		{
			wait(&status);
		}
		else
		{
			handle_command_1(cmd, parameters, NULL);
		}
	}
	return (0);