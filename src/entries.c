/*
** EPITECH PROJECT, 2021
** entries
** File description:
** entries
*/

#include "my.h"
#include "42sh.h"
#include <stdlib.h>
#include <stdio.h>

static char **add_double(char **av, char **new, int i, int j)
{
    new[j + 2] = new[j - 1];
    new[j + 1] = malloc(sizeof(char) * 2);
    my_strcpy(new[j + 1], "|\0");
    new[j] = malloc(sizeof(char) * (my_strlen(av[i + 1]) + 1));
    my_strcpy(new[j], av[i + 1]);
    new[j - 1] = malloc(sizeof(char) * 6);
    my_strcpy(new[j - 1], "_123_\0");
    return (new);
}

static char **add_simple(char **av, char **new, int i, int j)
{
    new[j + 2] = new[j - 1];
    new[j + 1] = malloc(sizeof(char) * 2);
    my_strcpy(new[j + 1], "|\0");
    new[j] = malloc(sizeof(char) * (my_strlen(av[i + 1]) + 1));
    my_strcpy(new[j], av[i + 1]);
    new[j - 1] = malloc(sizeof(char) * 4);
    my_strcpy(new[j - 1], "cat\0");
    return (new);
}

static void transform_entrie_two(char **av, int i, int j, char **new)
{
    add_simple(av, new, i, j);
    i++;
    j = j + 3;
}

static char **transform_entrie(char **av, int nb)
{
    char **new; int i; int j;

    new = malloc(sizeof(char *) * (nb + tablen(av) + 1));
    for (i = 0, j = 0; av[i] != NULL; i++) {
        if (!my_strcmp(av[i], "<<")) {
            add_double(av, new, i, j);
            i++;
            j = j + 3;
        } else if (!my_strcmp(av[i], "<")) {
            transform_entrie_two(av, i, j, new);
        } else {
            new[j] = malloc(sizeof(char) * (my_strlen(av[i]) + 1));
            my_strcpy(new[j], av[i]);
            j = j + 1;
        }
    }
    new[j] = NULL;
    free_arr(av);
    return (new);
}

char *change_entrie(char *line)
{
    char **av;
    int size = 0;
    int k = 0;
    char *new_line = add_space(line);

    av = str_to_arr(new_line, ' ');
    av = transform_entrie(av, count_entrie(new_line));
    free(new_line);
    for (int i = 0; av[i] != NULL; i++)
        size = size + my_strlen(av[i]) + 1;
    new_line = malloc(sizeof(char) * size);
    change_entrie_two(new_line, av, k);
    free_arr(av);
    return (new_line);
}