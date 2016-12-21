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

/* --Builtin Struct--*/
typedef struct builtins_s
{
	char *name;
	int (*func)(char **);
} builtins_t;

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

/* --General Functions-- */
void loop(void);
char **make_args(char *input);
int wordcount(char *str);
char *tokenize(char *input, const char *delim, char **saveptr);
void output(char **args);
void execute(char **args);
void *smart_alloc(size_t size);
void sighandler(int sig_num);

/* --Path Functions-- */
char **check_path(char **args);
char *path_concat(char *s1, char *s2);
char *hosh_copypath(char *name);

/* --Builtin Functions-- */
int check_builtins(char **args);
int hosh_exit(char **args);

/* --Env Functions-- */
int hosh_printenv(char **args);
int hosh_unsetenv(char *name);
int hosh_setenv(char *name, char *value, int overwrite);
char *hosh_findenv(char *name);
int hosh_addenv(char *newvar, char *name);

/* --Print Functions-- */
void _puts(char *str);
int _putchar(char c);

/* --String Functions-- */
char *_strdup(char *str);
int _strlen(char *s);
char *_strchr(char *s, char c);
char *_strpbrk(char *s, const char *accept);
int _strspn(char *s, const char *accept);
int _strncmp(char *s1, char *s2, int n);
char *str_concat(char *s1, char *s2);
char *_strcpy(char *dest, char *src);

/* --Math Functions-- */
int _atoi(char *str);

/* --Corbin-Functions-- */
char *_getenv(char *name);
char *_strcat(char *frontstr, char *backstr);
char **check_path(char **commands);
int hosh_exit(char **commands);
int _strncmp(char *c1, char *c2, int n);
int check_builtins(char **commands);
void sighandler(int sig_num);
char *hosh_copypath(char *name);
#endif /* SHELL_H */
