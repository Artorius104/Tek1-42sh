/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** mysh$
*/

#include "my.h"
#include "42sh.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int ret = 0;

void exec_fork(char **av, char **env, int do_fork)
{
    int status;
    pid_t pid;

    if (do_fork) {
        pid = fork();
        if (pid == 0)
            exec_cmd(av, env);
        else
            wait(&status);
        print_error(status);
    } else
        exec_cmd(av, env);
}

char **exec_2(char **av, char **env, int do_fork)
{
    if (!my_strcmp(av[0], "exit")) {
        printf("%s", YEL "\n42sh has stopped.\n");
        return (NULL);
    }
    if (!my_strcmp(av[0], "_123_")) {
        my_double_entrie(av);
        return (env);
    }
    if (!my_strcmp(av[0], "cd")) {
        env = my_cd(env, av);
        return (env);
    }
    exec_fork(av, env, do_fork);
    return (env);
}

char **exec(char **av, char **env, int do_fork)
{
    if (!my_strcmp(av[0], "env")) {
        my_env(env);
        return (env);
    }
    if (!my_strcmp(av[0], "setenv")) {
        env = my_setenv(env, av);
        return (env);
    }
    if (!my_strcmp(av[0], "unsetenv")) {
        env = my_unsetenv(env, av);
        return (env);
    }
    if (!my_strcmp(av[0], "echo")) {
        my_echo(av);
        return (env);
    }
    return (exec_2(av, env, do_fork));
}

char **exec_line(char *line, char **env, int do_fork, char c)
{
    char **av;

    if ((ret != 0 && c == '&') || (ret == 0 && c == '|')) {
        ret = 0;
        return env;
    }
    formate(line);
    if (error_redir(line))
        return error_msg(env);
    count_entrie(line) ? line = change_entrie(line): 0;
    if (exists_redir(line) >= 0)
        exec_redir(line, env);
    else if (exists_pipe(line) >= 0)
        exec_pipe(line, env);
    else {
        av = str_to_arr(line, ' ');
        env = exec(av, env, do_fork);
        free_arr(av);
    }
    return (env);
}

void minishell(char **env)
{
    char *line; char *new_line; char **cmd;

    while (1) {
        line = my_line();
        if (line == NULL)
            return;
        if (my_strlen(line) > 0) {
            new_line = change_sep(line);
            cmd = str_to_arr(new_line, ';');
            free(new_line);
            for (int i = 0; cmd[i] != NULL; i++)
                env = exec_line(cmd[i], env, 1, get_separator(line, i));
            if (env == NULL) {
                free(line);
                return;
            }
        }
        free(line);
    }
}
