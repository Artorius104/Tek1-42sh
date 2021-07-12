/*
** EPITECH PROJECT, 2021
** entrie
** File description:
** 42sh
*/

#include "42sh.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>

static char *my_getline(void)
{
    char *line = NULL;
    size_t size = 0;
    int len;

    if (getline(&line, &size, stdin) == -1) {
        printf("%s", YEL "\n\n42sh has stopped by Ctrl + D.\n");
        exit(0);
    }
    len = my_strlen(line);
    if (line[len - 1] == '\n')
        line[len - 1] = '\0';
    return (line);
}

void my_double_entrie(char **av)
{
    char *end = av[1];
    char *line = NULL;

    while (my_strcmp(line, end)) {
        if (line != NULL)
            free(line);
        line = my_getline();
        if (my_strcmp(line, end) && line != NULL)
            dprintf(1, "%s\n", line);
    }
    if (line != NULL)
        free(line);
    ret = 0;
}

int error_redir(char *str)
{
    int i;

    for (i = 0; (str[i] != '\0' && str[i] != '<' && str[i] != '>'); i++);
    if (str[i] == '\0')
        return (0);
    if (str[i] == str[i + 1])
        i++;
    for (i = i + 1; str[i] != '\0'; i++) {
        if (str[i] == '|' || str[i] == '<' || str[i] == '>')
            return (84);
        if (str[i] != ' ')
            return (0);
    }
    return (84);
}
