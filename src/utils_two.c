/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** utils two
*/

#include "my.h"
#include "42sh.h"
#include <stdlib.h>

void my_env(char **env)
{
    int i;

    for (i = 0; env[i] != NULL; i++) {
        my_putstr(env[i]);
        my_putstr("\n");
    }
    ret = 0;
}