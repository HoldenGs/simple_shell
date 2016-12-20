#include "shell.h"

/**
 * _strcat - combine two strings together
 * @frontstr: The string to start the new combined string
 * @backstr: The string to attach to the end of new combined string
 *
 * Return: Pointer to the new string
 */
char *_strcat(char *frontstr, char *backstr)
{
        char *newstr;
        int frontlen, backlen, frontpos, backpos, newstrpos;

        frontlen = backlen = frontpos = backpos = newstrpos = 0;
        frontlen = _strlen(frontstr);
        backlen = _strlen(backstr);
        newstr = smart_alloc((backlen + frontlen + 2) * sizeof(char));
        while (frontstr[frontpos] != '\0')
        {
                newstr[newstrpos] = frontstr[frontpos];
                newstrpos++;
                frontpos++;
        }
        newstr[newstrpos] = '/';
        newstrpos++;
        while (backstr[backpos] != '\0')
        {
                newstr[newstrpos] = backstr[backpos];
                newstrpos++;
                backpos++;
        }
        newstr[newstrpos] = '\0';
        return (newstr);
}
