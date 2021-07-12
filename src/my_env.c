/*
** EPITECH PROJECT, 2021
** my_env
** File description:
** my_env
*/

#include "my.h"
#include "42sh.h"
#include <stddef.h>
#include <stdlib.h>

int check_env_error(char **av, int i)
{
    if (av[1] == NULL)
        return (0);
    for (i = 0; av[i] != NULL; i++);
    if (i > 3) {
        my_puterror("setenv: Too many arguments.\n");
        return (1);
    }
    if (!(av[1][0] >= 'a' && av[1][0] <= 'z') &&
        !(av[1][0] >= 'A' && av[1][0] <= 'Z')) {
            my_puterror("setenv: Variable name must begin with a letter.\n");
            return (1);
    }
    for (i = 1; av[1][i] != '\0'; i++)
        if (!is_alpha_num(av[1][i])) {
            my_puterror("setenv: Variable name ");
            my_puterror("must contain alphanumeric characters.\n");
            return (1);
        }
    return (0);
}

static void put_last_env_var(char **env, char *new, int i)
{
    for (i = 0; env[i] != NULL; i++);
    env[i] = new;
    env[i + 1] = NULL;
    ret = 0;
}

static int print_env(char **av, char **env)
{
    if (av[1] == NULL) {
        my_env(env);
        ret = 0;
        return -1;
    }
    return 0;
}

char **my_setenv(char **env, char **av)
{
    int i;
    char *new;

    if (check_env_error(av, 0)) {
        ret = -1;
        return (env);
    }
    if (print_env(av, env) == -1)
        return (env);
    new = my_strcat_3(av[1], "=", av[2]);
    i = check_env(env, av[1]);
    if (i != -1) {
        free(env[i]);
        env[i] = new;
        ret = 0;
        return (env);
    }
    put_last_env_var(env, new, i);
    return (env);
}

char **my_unsetenv(char **env, char **av)
{
    int i;
    int j;

    for (i = 1; av[i] != NULL; i++) {
        j = check_env(env, av[i]);
        if (j != -1) {
            free(env[j]);
            for (j = j + 1; env[j] != NULL; j++)
                env[j - 1] = env[j];
            env[j - 1] = NULL;
        }
    }
    ret = 0;
    return (env);
}
