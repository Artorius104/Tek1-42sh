/*
** EPITECH PROJECT, 2021
** my_str
** File description:
** my_str
*/

#include "my.h"
#include "42sh.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int my_strlen(char *str)
{
    int i;

    if (str == NULL)
        return (0);
    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

void my_putstr(char *str)
{
    if (str != NULL)
        write(1, str, my_strlen(str));
}

void my_puterror(char *str)
{
    if (str != NULL)
        write(2, str, my_strlen(str));
}

int my_strcmp(char *s1, char *s2)
{
    int i;

    if (s1 == NULL || s2 == NULL)
        return (1);
    for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}

char *my_strcat_3(char *s1, char *s2, char *s3)
{
    int size;
    char *new;
    int i;
    int j = 0;

    if (s3 == NULL)
        s3 = "\0";
    size = my_strlen(s1) + my_strlen(s2) + my_strlen(s3);
    new = malloc(sizeof(char) * (size + 1));
    for (i = 0; s1[i] != '\0'; i++, j++)
        new[j] = s1[i];
    for (i = 0; s2[i] != '\0'; i++, j++)
        new[j] = s2[i];
    for (i = 0; s3[i] != '\0'; i++, j++)
        new[j] = s3[i];
    new[j] = '\0';
    return (new);
}