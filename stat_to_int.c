#include "main.h"

/**
 * stat_to_int - Convert a status in a string to an integer.
 * @s: The pointer to string to convert
 *
 * Return: A positive integer, -1 if any error
 */

int    stat_to_int(char *s)
{
        int             i;
        unsigned int    status;

        i = 0;
        status = 0;

        if (_strcmp(s, "-0") == 0)
                return (0);
        if (s[i] == '+')
                i++;
        while (s[i] != '\0')
        {
                while ((s[i] >= '0' && s[i] <= '9'))
                {
                        status = status * 10 + s[i] - '0';
                        i++;
                }
                if (s[i] == '\0')
                {
                        break;
                }
                if ((s[i] < '0' || s[i] > '9'))
                {
                        return (-1);
                }
                i++;
        }
        return (status);
}
