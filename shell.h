#ifndef SHELL_H
#define SHELL_H
#define BUFSIZE 1024

/* --Linked List Structure-- */
/**
 * listnode_s - singly linked list
 * @string: string data
 * @next: next node
 *
 * Description: singly linked list, for use as a command
 * list which changes size to accomodate expansion
 */
typedef struct listnode_s
{
	char *string;
	struct listnode_s *next;
} listnode_t;

/* --Standard Libraries-- */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/* --Custom Functions--*/
void loop(void);
char *read_line(void);
char **parse(char *line);
int execute(char **args);
int launch(char **args);
int cd_func(char **args);
int help_func(char **args);
int exit_func(char **args);
int builtin_count(void);
int _strcmp(char *s1, char *s2);

#endif /* End SHELL_H */
