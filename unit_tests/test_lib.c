/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** unit test lib
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
#include <unistd.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_putstr, simple_string, .init = redirect_all_std)
{
    my_putstr("hello world");

    cr_assert_stdout_eq_str("hello world");
}

Test(my_strlen, display_int, .init = redirect_all_std)
{
    char str[] = "astek";

    cr_assert_eq(my_strlen(str), strlen(str));
}

Test(my_strlen_fail, display_int, .init = redirect_all_std)
{
    char *str = NULL;

    int len = my_strlen(str);

    cr_assert_eq(len, 0);
}

Test(strcmp, simple_string, .init = redirect_all_std)
{
    char *dest = "hello";

    if (my_strcmp(dest, "hello") == 0)
        write(1, "true !", 6);
    cr_assert_stdout_eq_str("true !");
}

Test(strcmp_false, simple_string, .init = redirect_all_std)
{
    char *dest = "hello";

    if (my_strcmp(dest, "abc") != 0)
        write(1, "false !", 7);
    cr_assert_stdout_eq_str("false !");
}

Test(my_strcpy, simple_string, .init = redirect_all_std)
{
    char *dest = malloc(sizeof(char) * 6);
    char *src = "Hello";

    my_strcpy(dest, src);
    write(1, src, my_strlen(src));

    cr_assert_stdout_eq_str("Hello");
}

Test(strcat_3, simple_string, .init = redirect_all_std)
{
    char *str = "Hello ";
    char *dest = "World ";
    char *src = "!";
    char *cat = my_strcat_3(str, dest, src);

    write(1, cat, my_strlen(cat));
    cr_assert_stdout_eq_str("Hello World !");
}

Test(strcat_3_empty, simple_string, .init = redirect_all_std)
{
    char *str = "Hello ";
    char *dest = "World ";
    char *src = NULL;
    char *cat = my_strcat_3(str, dest, src);

    write(1, cat, my_strlen(cat));
    cr_assert_stdout_eq_str("Hello World ");
}

Test(str_to_arr, display_char, .init = redirect_all_std)
{
    char *str = "Hello World !";
    char **buffer = NULL;

    buffer = str_to_arr(str, ' ');
    
    buffer[0] = "Hello";
    buffer[1] = "World";
    buffer[2] = "!";
    write(1, buffer[0], my_strlen(buffer[0]));
    write(1, buffer[1], my_strlen(buffer[1]));
    write(1, buffer[2], my_strlen(buffer[2]));
    cr_assert_stdout_eq_str("HelloWorld!");
}