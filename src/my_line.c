/*
** EPITECH PROJECT, 2020
** my_line
** File description:
** my_line
*/

#include "my.h"
#include "42sh.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char *del_char(char *str, int pos)
{
    int i;

    for (i = pos; str[i] != '\0'; i++)
        str[i] = str[i + 1];
    str[i] = '\0';
    return (str);
}

char *remove_space(char *str)
{
    int i;

    while (str[0] == ' ')
        del_char(str, 0);
    for (i = 1; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i - 1] == ' ') {
            del_char(str, i);
            i--;
        }
    }
    for (i = my_strlen(str) - 1; i > 0; i++)
        if (str[i] == ' ')
            str[i] = '\0';
        else
            return (str);
    return (str);
}

char *replace_tab(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == '\t')
            str[i] = ' ';
    return (str);
}

char *my_line(void)
{
    char *line = NULL;
    size_t size = 0;
    int len;

    prompt();
    if (getline(&line, &size, stdin) == -1) {
        printf("%s", YEL "\n\n42sh has stopped by Ctrl + D.\n");
        exit(0);
    }
    len = my_strlen(line);
    if (line[len - 1] == '\n')
        line[len - 1] = '\0';
    return (line);
}

char *formate(char *str)
{
    char c;

    replace_tab(str);
    remove_space(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (i > 0) {
            c = str[i - 1];
            if (str[i] == ' ' && (c == '|' || c == '>')) {
                del_char(str, i);
                i--;
            }
        }
        c = str[i + 1];
        if (str[i] == ' ' && (c == '|' || c == '>')) {
            del_char(str, i);
            i--;
        }
    }
    return (str);
}
