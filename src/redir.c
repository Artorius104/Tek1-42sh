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
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

int check_error_redir(char *line)
{
    int quote = 0;
    char c;
    int i;

    for (i = 0; line[i] != '>'; i++);
    for (; line[i] == '>'; i++);
    for (; line[i] != '\0'; i++) {
        c = line[i];
        if (c == '"' && quote == 0)
            quote = 1;
        else if (c == 34)
            quote = 0;
        if ((c == '>' || c == '<' || c == '|') && quote == 0) {
            my_puterror("Ambiguous output redirect.\n");
            return (1);
        }
    }
    return (0);
}

int exists_redir(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '>')
            return (i);
    return (-1);
}

static void get_argv(char *line, char **line1, char **line2, int *r)
{
    int len = exists_redir(line);
    char *cmd1 = malloc(sizeof(char) * len + 1);
    char *cmd2 = malloc(sizeof(char) * (my_strlen(line) - len));
    int i = 0;
    int j = 0;

    for (i = 0; line[i] != '>'; i++, j++)
        cmd1[j] = line[i];
    cmd1[j] = '\0';
    i++;
    line[i] == '>' ? i++, *r = 1: 0;
    for (j = 0; line[i] != '\0'; i++, j++)
        cmd2[j] = line[i];
    cmd2[j] = '\0';
    cmd1 = formate(cmd1);
    cmd2 = formate(cmd2);
    *line2 = cmd2;
    *line1 = cmd1;
}

int create_file(char *file, int r)
{
    int fd;

    if (r == 0)
        fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    else
        fd = open(file, O_CREAT | O_APPEND | O_WRONLY, 0644);
    return (fd);
}

void exec_redir(char *line, char **env)
{
    char *cmd1; char *cmd2; int status; pid_t pid; int fd; int r = 0;

    if (check_error_redir(line))
        return;
    get_argv(line, &cmd1, &cmd2, &r);
    fd = create_file(cmd2, r);
    free(cmd2);
    pid = fork();
    if (pid == 0) {
        dup2(fd, STDOUT_FILENO);
        exec_line(cmd1, env, 0, ';');
        free(cmd1);
        exit(0);
    }
    close(fd);
    wait(&status);
    free(cmd1);
    print_error(status);
}
