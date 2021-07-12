/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "my.h"
#include "42sh.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

char **copy_env(char **env)
{
    char **new = malloc(sizeof(char *) * 500);
    int i;
    int j;

    for (i = 0; env[i] != NULL; i++) {
        new[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        for (j = 0; env[i][j] != '\0'; j++)
            new[i][j] = env[i][j];
        new[i][j] = '\0';
    }
    new[i] = NULL;
    return (new);
}

int main(int ac, char **av, char **nv)
{
    (void)av;
    char **env = NULL;
    char *pwd[3];

    if (ac != 1 || nv == NULL)
        return (84);
    env = copy_env(nv);
    if (check_env(env, "OLDPWD") == -1) {
        pwd[0] = "setenv";
        pwd[1] = "OLDPWD";
        pwd[2] = NULL;
        my_setenv(env, pwd);
    }
    printf("%s\n", GRN "42sh is working...\n");
    minishell(env);
    free_arr(env);
    return (0);
}