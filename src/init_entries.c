/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** init entries files
*/

#include "my.h"
#include <stdlib.h>

char *first_args(char *line, char c)
{
    char *str = NULL;
    int mal = 1;
    int i = 0;

    for (int i = 0; line[i] != c; ++i, ++mal);
    str = malloc(sizeof(char) * mal);
    for (i = 0; line[i] != c; ++i)
        str[i] = line[i];
    str[i] = '\0';

    return str;
}

char *second_args(char *line, char c)
{
    char *str = NULL;
    int i = 0;
    int t = 0;

    for (i = 0; line[i] != c; ++i);
    ++i;
    str = malloc(sizeof(char) * i + 1);
    for (t = 0; line[i] != '\0'; ++i, ++t) {
        str[t] = line[i];
    }
    str[t] = '\0';

    return str;
}

static char *just_one_space(char *line, char *f_arg, char *s_arg, char *redir)
{
    line = my_strcat_3(f_arg, redir, s_arg);
    formate(line);
    free(f_arg);
    free(s_arg);
    return line;
}

char *add_space(char *line)
{
    char *first_arg = first_args(line, '<');
    char *second_arg = second_args(line, '<');
    char *redir = " < ";

    for (int i = 0; line[i] != '\0'; ++i) {
        if (line[i] == '<' && line[i - 1] != ' ' && line[i + 1] != ' ') {
            line = my_strcat_3(first_arg, redir, second_arg);
            free(first_arg);
            free(second_arg);
            return line;
        }
        else if (line[i] == '<' && (line[i - 1] != ' ' || line[i + 1] != ' '))
	        return just_one_space(line, first_arg, second_arg, redir);
    }
    free(first_arg);
    free(second_arg);
    return line;
}

void change_entrie_two(char *line, char **av, int k)
{
    for	(int i = 0; av[i] != NULL; i++) {
        for (int j = 0; av[i][j] != '\0'; j++, k++) {
            line[k] = av[i][j];
        }
        if (av[i + 1] != NULL) {
            line[k] = ' ';
            k++;
        }
    }
    line[k] = '\0';
}
