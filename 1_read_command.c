#include "main.h"

/**
 * read_command_1 - this is a command that reads from stdin
 * @cmd: the command
 * @par: the parameters of the command
 * Return: void
 */

void read_command_1(char cmd[])
{
	char line[1024];

	fgets(line, 1024, stdin);
	line[strcspn(line, "\n")] = 0;
	strcpy(cmd, line);
}
