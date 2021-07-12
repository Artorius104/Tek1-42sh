/*
** EPITECH PROJECT, 2021
** exec
** File description:
** exec
*/

#include "my.h"
#include "42sh.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

void print_error(int status)
{
    int sig;

    if (WIFSIGNALED(status)) {
        sig = WTERMSIG(status);
        if (WCOREDUMP(status)) {
            if (sig == 8)
                my_puterror("Floating exception (core dumped)\n");
            else
                my_puterror("Segmentation fault (core dumped)\n");
        } else {
            if (sig == 8)
                my_puterror("Floating exception\n");
            else
                my_puterror("Segmentation fault\n");
        }
    }
}

void my_execve(char *name, char **av, char **env)
{
    DIR *dir = opendir(name);

    if (dir == NULL) {
        execve(name, av, env);
        ret = 0;
        return;
    }
    my_puterror(name);
    my_puterror(": Permission denied.\n");
    ret = -1;
}

void my_exec(char **av, char **path, char **env)
{
    char *filepath;
    int i;

    if (!access(av[0], X_OK)) {
        my_execve(av[0], av, env);
        exit(0);
    }
    if (path != NULL) {
        for (i = 0; path[i] != NULL; i++) {
            filepath = my_strcat_3(path[i], "/", av[0]);
            if (!access(filepath, X_OK)) {
                my_execve(filepath, av, env);
                exit(0);
            }
            free(filepath);
        }
    }
    my_puterror(my_strcat_3(av[0], ": Command not found.\n", NULL));
    ret = -1;
    exit(0);
}

void exec_cmd(char **av, char **env)
{
    int i = check_env(env, "PATH");
    char **path = NULL;

    if (i != -1)
        path = str_to_arr(env[i] + 5, ':');
    my_exec(av, path, env);
    if (path != NULL)
        free_arr(path);
}
