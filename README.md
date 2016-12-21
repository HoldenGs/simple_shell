#Holberton School - Simple Shell Project

A project to code a simple shell for Holberton School. The project is to replicate the basic functionality of a Linux shell to test our knowledge of the C programming language. There were restrictions placed on which C standard library functions we were allowed to use. So, many  functions were recreated for use inside the code.

###How to Install
Compile the code like so:
```
gcc -Wall -Wextra -Werror -pedantic *.c -o hsh
```
This will cause all warnings to act as compilation errors and will name the executable file hsh.

##Usage
Run like so:
```
./hsh
```
The shell can accept commands, which should be given like so:
```
$ command args [...]
```

##Files & Contents
- arg_ops.c: Functions to tokenize user input and allocate proper amount of space in memory. Functions inside: wordcount(), make_args()
- builtins.c: Builtin functions made for our shell. Functions inside: hosh_setenv(), hosh_unsetenv(), hosh_exit(), hosh_printenv()
- builtins_help.c: Functions to print help for the builtin functions. Functions inside: help_exit(), help_unsetenv(), help_setenv(), help_env(), help_help()
- check_builtins.c: Check to see if input is a builtin function. Functions inside: check_builtins()
- check_path.c: Find the PATH, then append the command to the directories in PATH to find given command. Functions inside: check_path(), path_concat(), _copypath()
- env_ops.c: Different functions handling the environment variables. Functions inside: _unsetenv(), _findenv(), _addenv()
- execute.c: Execute given commands. Functions inside: output(), execute()
- loop.c: Run the main loop of the program. Functions inside: main(), loop()
- man_1_simple_shell: The man page for the shell project
- math_ops.c: Mathematical functions. Functions inside: _atoi()
- memory.c: Functions handling memory. Functions inside: smart_alloc(), free_array()
- print.c: Functions to print with. Functions inside: _puts(), _putchar()
_ print_help.c: Print a list of all builtins. Functions inside: print_help()
- shell.h: Contains all function prototypes, structs, and header files necessary for all other functions
- string_ops.c: One of two files containing functions to manage string variables. Functions inside: _strlen(), _strdup(), _strspn(), _strchr(), _strpbrk()
- string_ops_2.C: Second of two files containing functions to manage string variables. Functions inside: _strncmp(), str_concat(), _strcpy()
- tokenize.c: Tokenize the given input. Functions inside: tokenize()

## Authors
<p>Holden Grissett</p>
<p>Corbin Coleman</p>