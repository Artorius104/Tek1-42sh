/*
** EPITECH PROJECT, 2021
** check_env
** File description:
** check_env
*/

#include "my.h"
#include "42sh.h"
#include <stddef.h>

int env_cmp(char *env, char *name)
{
    int i;

    for (i = 0; name[i] != '\0' && env[i] != '\0'; i++) {
        if (name[i] != env[i])
            return (0);
    }
    if (name[i] != '\0')
        return (0);
    if (env[i] != 61)
        return (0);
    return (1);
}

int check_env(char **env, char *name)
{
    int i;

    for (i = 0; env[i] != NULL; i++)
        if (env_cmp(env[i], name))
            return (i);
    return (-1);
}
