/*
** EPITECH PROJECT, 2021
** my_cd
** File description:
** my_cd
*/

#include "my.h"
#include "42sh.h"
#include <dirent.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

void prompt(void)
{
    char *buf = malloc(sizeof(char) * UCHAR_MAX);

    getcwd(buf, UCHAR_MAX);
    printf("%s%s $> ", color, buf);
    free(buf);
}

int check_dir(char *name)
{
    if (opendir(name) != NULL) {
        return (0);
    } else {
        if (open(name, O_RDONLY) == -1) {
            my_puterror(name);
            my_puterror(": No such file or directory.\n");
            return (1);
        } else {
            my_puterror(name);
            my_puterror(": Not a directory.\n");
            return (1);
        }
    }
}

void get_old_dir(char **env, int old)
{
    chdir("");
    chdir(env[old] + 7);
    printf("%s\n", (env[old] + 7));
    ret = 0;
}

int change_dir(char **env, char **av)
{
    int home = check_env(env, "HOME");
    int old = check_env(env, "OLDPWD");

    if (av[1] == NULL) {
        chdir("");
        chdir(env[home] + 5);
        ret = 0;
        return (0);
    }
    if (!my_strcmp(av[1], "-") && old != -1) {
        get_old_dir(env, old);
        return (0);
    } else if (!check_dir(av[1])) {
        chdir(av[1]);
        ret = 0;
        return (0);
    } else {
        ret = -1;
        return (84);
    }
}

char **my_cd(char **env, char **av)
{
    int pwd = check_env(env, "PWD");
    int old = check_env(env, "OLDPWD");
    char *path = malloc(sizeof(char) * UCHAR_MAX);
    char *old_pwd = my_strcat_3("OLDPWD", "=", getcwd(path, UCHAR_MAX));

    if (change_dir(env, av) == 0 && pwd != -1 && old != -1) {
        free(env[old]);
        env[old] = old_pwd;
        env[pwd] = my_strcat_3("PWD", "=", getcwd(path, UCHAR_MAX));
    } else {
        free(old_pwd);
        free(path);
    }
    return (env);
}
