#ifndef SHELL_H
#define SHELL_H
extern char **environ;

/* --Library Headers-- */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

/* --Functions-- */
void loop(void);
char **parse(char *input);
char *tokenize(char *input, const char *delim, char **saveptr);
void execute(char **input);
void _puts(char *str);
int _putchar(char c);

#endif /* SHELL_H */
