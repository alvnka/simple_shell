#ifndef MAIN_H
#define MAIN_H

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "string.h"
#include "sys/wait.h"
#include "sys/stat.h"
void read_command_1(char cmd[]);
void read_command(char *cmd, char *par[]);
void type_prompt(void);
char *find_command_path_1(char *command);
char *find_command_path(char *command);
int check_exit(char *cmd);
void handle_command(char *command, char **parameters, char **envp);
void handle_command_1(char *command, char **parameters, char **envp);

#endif
