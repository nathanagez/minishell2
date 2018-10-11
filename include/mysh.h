/*
** EPITECH PROJECT, 2017
** Project Minishell2
** File description:
** Description header file
*/

#ifndef _MYSH_H_
# define _MYSH_H_
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "macros.h"

list_t *new_element(char *path, int len);
list_t *get_path(char **env);
bool is_separator(char c, char *sep);
int signal_code(int code);
int free_darray(char **tab);
int check_access(char *path);
int check_is_dir(char *path);
int count_words(char *str, char *sep);
int count_letters(char *str, char *sep);
int is_builtin(char *cmd, char ***env, list_t **path);
int exec_cmd(char *str, char **env, list_t *path);
int free_list(list_t *list, int is_child);
char **str_to_wordtab(char *str, char *sep);
char **cp_env(char **env, char *line, int pos, int flag);
char *concat_path(list_t *s1, char *s2, char separator);
char *filename(char *str, int index);
char *has_redirections(char *cmd);
char *my_strcpy(char *s1, char *s2);
char *my_catsep(char *s1, char *s2, char sep);
char *my_gnlrealloc(char *src, int n);
char *get_cmd(char *cmd, char *cmdref, int start, int end);
char *get_next_line(int fd);
void find_oldpwd(char ***env);
void my_cd_style(char ***env, int i);
void find_pwd(char ***env, list_t **path);
void delete_line(char ***envp, int pos);
void free_tmpenv(char **envp);
void add_element(list_t **list, char *str, int len);
void parse_env(char *path_line, list_t **list);
void my_env(char **tab, char ***env, list_t **path);
void my_setenv(char **tab, char ***env, list_t **path);
void my_unsetenv(char **tab, char ***env, list_t **path);
void my_cd(char **tab, char ***env, list_t **path);
void my_jumper(char *cmd, int *i);
void my_ctrl_c(__attribute__((unused))int empty);
void put_error(int status);
int red_out(char *file, int end);
int red_din(char *file);
int red_in(char *file, int end);
int init_pipe(char **cmd_pipe, int i);
int has_pipe(char *cmd, char ***env, list_t **path);
int my_strlen(char *str);
int my_putstr(char *str);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, int n);
int write_err(char *str);
int return_buffer(int fd, char *str);
int parent(char *str, char ***env, list_t **list);
int command_parser(char *gnl, char ***env, list_t **path);
int prompt(list_t **path, char ***env);

#endif