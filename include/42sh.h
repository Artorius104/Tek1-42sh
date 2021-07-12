/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** shell.h
*/

#ifndef SHELL_H_
#define SHELL_H_

extern int ret;

//check_env
int check_env(char **env, char *name);

//entries
char *change_entrie(char *line);
int count_entrie(char *line);
void my_double_entrie(char **av);
void change_entrie_two(char *line, char **av, int k);
char *add_space(char *line);
char *first_args(char *line, char c);
char *second_args(char *line, char c);

//cd
char **my_cd(char **env, char **av);
void prompt(void);

//echo
void my_echo(char **av);

//env
char **my_setenv(char **env, char **av);
char **my_unsetenv(char **env, char **av);
void my_env(char **env);

//my_line
char *del_char(char *str, int pos);
char *formate(char *str);
char *my_line(void);

//pipe
void exec_pipe(char *line, char **env);
int exists_pipe(char *str);

//minishell
void minishell(char **env);
char **exec_line(char *line, char **env, int do_fork, char c);

//execve
void exec_cmd(char **av, char **env);
void print_error(int status);
void my_exec(char **av, char **path, char **env);

//redir
void exec_redir(char *line, char **env);
int exists_redir(char *str);
int error_redir(char *str);

//utils
char get_separator(char *line, int j);
char check_sep(char *line);
void free_arr(char **arr);
int count_entrie(char *line);
char *change_sep(char *line);
char **error_msg(char **env);

#endif
