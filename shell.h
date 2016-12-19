#ifndef SHELL_H
#define SHELL_H
#define OUT 0
#define IN 1
extern char **environ;

/* --Address List-- */
typedef struct addresses
{
	void *address;
	struct addresses *next;
} addr_t;

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
char **make_args(char *input);
char *tokenize(char *input, const char *delim, char **saveptr);
void output(char **args);
void execute(char **args);
void *smart_alloc(size_t size);
void _puts(char *str);
int _putchar(char c);
int wordcount(char *str);
char *_strdup(char *str);
int _strlen(char *s);
char *_strpbrk(char *s, const char *accept);
int _strspn(char *s, const char *accept);

#endif /* SHELL_H */
