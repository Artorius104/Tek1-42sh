/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** utils function
*/

#include "42sh.h"
#include "my.h"
#include <stdlib.h>

int count_entrie(char *line)
{
    int n = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '<')
            n++;
    }
    return (n);
}

char **error_msg(char **env)
{
    my_puterror("Missing name for redirect.\n");
    ret = 0;
    return (env);
}

char check_sep(char *line)
{
    for (int i = 0; line[i] != '\0'; ++i) {
        if (line[i] == ';')
            return ';';
        if (line[i] == '&' && line[i + 1] == '&') {
            line[i + 1] = ' ';
            return '&';
        }
        if (line[i] == '|' && line[i + 1] == '|') {
            line[i + 1] = ' ';
            return '|';
        }
    }
    return ';';
}

char get_separator(char *line, int j)
{
    int i;
    int n = 0;

    if (j == 0)
        return (';');
    for (i = 0; line[i] != '\0'; i++) {
        if (line[i] == ';')
            n++;
        if (line[i] == '&' || line[i] == '|') {
            n++;
            i++;
        }
        if (n == j)
            return (line[i]);
    }
    return (';');
}

char *change_sep(char *line)
{
    char *str = malloc(sizeof(char) * (my_strlen(line) + 1));
    int i;

    my_strcpy(str, line);
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '&' && str[i + 1] == '&') {
            str[i] = ';';
            del_char(str, i + 1);
        }
        if (str[i] == '|' && str[i + 1] == '|') {
            str[i] = ';';
            del_char(str, i + 1);
        }
    }
    return (str);
}
