/*
** EPITECH PROJECT, 2021
** pipe
** File description:
** pipe
*/

#include "my.h"
#include "42sh.h"
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int check_error_pipe(char *line)
{
    char **av = str_to_arr(line, '|');

    for (int i = 0; av[i] != NULL; i++) {
        formate(av[i]);
        if (my_strlen(av[i]) == 0) {
            free_arr(av);
            return (1);
        }
    }
    free_arr(av);
    return (0);
}

int exists_pipe(char *str)
{
    int n = 0;
    int first = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '|') {
            n++;
            if (first == 0)
                first = i;
        }
    if (n == 0)
        return (-1);
    else
        return (first);
}

static void get_argv(char *line, char **line1, char **line2)
{
    int len = exists_pipe(line);
    char *cmd1 = malloc(sizeof(char) * len + 1);
    char *cmd2 = malloc(sizeof(char) * (my_strlen(line) - len));
    int i = 0;
    int j = 0;

    for (i = 0; line[i] != '|'; i++, j++)
        cmd1[j] = line[i];
    cmd1[j] = '\0';
    i++;
    for (j = 0; line[i] != '\0'; i++, j++)
        cmd2[j] = line[i];
    cmd2[j] = '\0';
    cmd1 = formate(cmd1);
    cmd2 = formate(cmd2);
    *line2 = cmd2;
    *line1 = cmd1;
}

void exec_pipe_2(char **env, char *cmd, int *pipefd)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        if (exists_pipe(cmd) > 0) {
            exec_pipe(cmd, env);
            free(cmd);
        } else
            exec_line(cmd, env, 0, ';');
        exit(0);
    }
    close(pipefd[0]);
    close(pipefd[1]);
    wait(&status);
    print_error(status);
    free(cmd);
}

void exec_pipe(char *line, char **env)
{
    char *cmd1; char *cmd2; int status; pid_t pid; int pipefd[2];

    if (check_error_pipe(line)) {
        my_puterror("Invalid null command.\n");
        return;
    }
    get_argv(line, &cmd1, &cmd2);
    pipe(pipefd);
    pid = fork();
    if (pid == 0) {
        dup2(pipefd[1], STDOUT_FILENO);
        exec_line(cmd1, env, 0, ';');
        exit(0);
    }
    wait(&status);
    print_error(status);
    free(cmd1);
    exec_pipe_2(env, cmd2, pipefd);
}
