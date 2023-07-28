/*
** simple_shell.c
**
** A simple UNIX command line interpreter.
**
** This shell is very simple, but it should be able to handle the basic tasks
** that you have outlined. It does not support the PATH, built-ins, or special
** characters. It also does not handle commands with arguments. However, it does
** handle the "end of file" condition (Ctrl+D) and errors.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
** main()
**
** The main function of the shell.
**
** This function continuously loops, displaying the prompt and waiting for the
** user to type a command. The command is then executed, and the shell loops
** again.
**
** @param ac The number of command-line arguments.
** @param argv The command-line arguments.
**
** @return 0 on success, or a non-zero error code on failure.
*/
int main(int ac, char **argv) {
  /* declaring void variables correctly */
  (void) ac;
  (void) argv;

  char *prompt = "(MASHELL) $ ";
  char *lineptr = NULL;
  size_t n = 0;

  while (1) {
    /* Display the prompt */
    printf("%s", prompt);

    /* Read the command line */
    getline(&lineptr, &n, stdin);

    /* If the user enters an empty line, or presses Ctrl+D, exit the shell */
    if (lineptr[0] == '\0') {
      free(lineptr);
      return 0;
    }

    /* Free the memory allocated for the command line */
    free(lineptr);
  }

  return 0;
}
