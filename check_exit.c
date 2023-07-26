#include "main.h"

/**
 * check_exit - checks if the user typed exit
 * @cmd: the command
 * Return: 1 if exit, 0 otherwise
*/
int check_exit(char *cmd)
{
	if (strcmp(cmd, "exit") == 0)
	{
		return (1);
	}
	return (0);
}
