/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** my_strcpy
*/

#include "my.h"
#include "42sh.h"
#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;
    int result = 0;

    while (i != n - 1 && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    result = s1[i] - s2[i];

    return result;
}

int tablen(char **buffer)
{
    int i = 0;

    if (buffer == NULL || buffer[0] == NULL)
        return i;

    for (; buffer[i] != NULL; ++i);

    return i;
}

int is_alpha_num(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    if (c >= 'a' && c <= 'z')
        return (1);
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}