/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
# define MY_H_
#define color "\e[0;96m"
#define NRM "\x1B[0m"
#define RED "\x1B[31m"
#define GRN "\e[6;1;32m"
#define YEL "\e[0;1;33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"

int my_strlen(char *str);
void my_putstr(char *str);
void my_puterror(char *str);
int my_strcmp(char *s1, char *s2);
char *my_strcat_3(char *s1, char *s2, char *s3);
char **str_to_arr(char *str, char c);
char *my_strcpy(char *dest, char const *src);
void free_arr(char **arr);
char *formate(char *str);
void print_error(int status);
int my_strncmp(char *s1, char *s2, int n);
int tablen(char **buffer);
int is_alpha_num(char c);

#endif
