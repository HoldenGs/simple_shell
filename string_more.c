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

/**
 * _atoi - Convert string into an integer
 * @str: String to convert to int
 *
 * Return: The int the string represents,
 * -1 if there are not only numbers in str
 */
int _atoi(char *str)
{
        int i, num;

        i = num = 0;
        while (str[i] != '\0')
        {
                if (str[i] < '0' || str[i] > '9')
                        return (-1);
                num = num * 10;
                num += str[i] - '0';
        }
        return (num);
}
