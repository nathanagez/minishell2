/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** Header file
*/

#include "mysh.h"

static builtin_t builtin_cmd[] = {
	{"env", &my_env},
	{"setenv", &my_setenv},
	{"cd", &my_cd},
	{"unsetenv", &my_unsetenv}
};

void my_env(__attribute__((unused))char **tab,
char ***env, __attribute__((unused))list_t **path)
{
	int i = 1;

	while ((*env)[++i]) {
		my_putstr((*env)[i]);
		my_putstr("\n");
	}
}

void my_setenv(char **cmd, char ***env, list_t **path)
{
	char **tmp = NULL;
	char *new_line = NULL;
	int i = -1;

	if (!cmd[1])
		return (my_env(cmd, env, path));
	new_line = my_catsep(cmd[1], cmd[2], '=');
	while ((*env)[++i]) {
		if (!my_strncmp(cmd[1], (*env)[i], my_strlen(cmd[1]))
		&& (*env)[i][my_strlen(cmd[1])] == '=') {
			(*env)[i] = new_line;
			free_list(*path, 1);
			*path = get_path(*env);
			return ;
		}
	}
	tmp = cp_env(*env, new_line, i, 0);
	free_tmpenv(*env);
	free(new_line);
	*env = tmp;
	free_list(*path, 1);
	*path = get_path(*env);
}

void my_unsetenv(char **cmd, char ***env, list_t **path)
{
	int i = -1;

	if (!cmd[1]) {
		write_err("unsetenv: Too few arguments.\n");
		signal_code(1);
		return ;
	}
	while ((*env)[++i]) {
		if (!my_strncmp(cmd[1], (*env)[i], my_strlen(cmd[1]))
		&& (*env)[i][my_strlen(cmd[1])] == '=') {
			delete_line(env, i);
			free_list(*path, 1);
			*path = get_path(*env);
			return ;
		}
	}
}

void my_cd(char **cmd, char ***env, list_t **path)
{
	int i = -1;

	if (!cmd[1]) {
		while ((*env)[++i]) {
			my_cd_style(env, i);
		}
		find_pwd(env, path);
		return ;
	}
	if (cmd[1][0] == '-' && !cmd[1][1])
		find_oldpwd(env);
	else if (chdir(cmd[1]) == -1) {
		check_access(cmd[1]);
		return ;
	}
	find_pwd(env, path);
}

int is_builtin(char *cmd, char ***env, list_t **path)
{
	int i = -1;
	char **commands = str_to_wordtab(cmd, " \t");

	if (commands == NULL || !commands[0])
		return (-1 * free_darray(commands));
	if (!my_strcmp("exit", commands[0]))
		return (free_darray(commands));
	while (++i < 4) {
		if (!my_strcmp(builtin_cmd[i].name, commands[0])) {
			builtin_cmd[i].fct(commands, env, path);
			free_darray(commands);
			return (1);
		}
	}
	free_darray(commands);
	return (0);
}
