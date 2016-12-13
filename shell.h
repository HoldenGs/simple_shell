#ifndef SHELL_H
#define SHELL_H

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
#include <fcntl.h>
#include <unistd.h>

/* --Vanilla Functions-- */
int main(int ac, char **av, char **env);

/* --Custom Functions--*/
void print_array(char **a, int n);

#endif /* End SHELL_H */
