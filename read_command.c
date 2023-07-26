#include "main.h"

/**
 * read_command - this is a command that reads from stdin
 * @cmd: the command
 * @par: the parameters of the command
 * Return: void
*/

void read_command(char cmd[], char *par[])
{
	char line[1024];
	int count = 0, i = 0;
	char *array[100], *pch;

	for (i = 0; i < 100; i++)
	{
		array[i] = NULL;
	}

	fgets(line, sizeof(line), stdin);

	pch = strtok(line, " \n");

	while (pch != NULL)
	{
		array[count++] = strdup(pch);
		pch = strtok(NULL, " \n");
	}

	strcpy(cmd, array[0]);

	for (i = 0; i < count; i++)
	{
		par[i] = array[i];
	}
	par[i] = NULL;
}
