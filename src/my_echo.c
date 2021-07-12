/*
** EPITECH PROJECT, 2021
** echo
** File description:
** 42sh
*/

#include "42sh.h"
#include "my.h"
#include <unistd.h>
#include <stdio.h>

void my_echo(char **av)
{
    for (int i = 1; av[i] != NULL; i++) {
        write(1, av[i], my_strlen(av[i]));
        if (av[i + 1] == NULL)
            write(1, "\n", 1);
        else
            write(1, " ", 1);
    }
    ret = 0;
}