#include "shell.h"

/**
 * print_help - Print out basic info on builtins
 */
void print_help()
{
        _puts("These commands are defined internally."
              "Type \'help\' to see this list.\n");
        _puts("Type \'help name\' to find out more about"
              "function \'name\'\n");
        _puts("  exit [status]\n");
        _puts("  env\n");
        _puts("  setenv [variable] [value]\n");
        _puts("  unsetenv [variable]\n");
        _puts("  help [name ...]\n");
}
