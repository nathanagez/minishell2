/*
** EPITECH PROJECT, 2017
** Project Minishell2
** File description:
** Description pwd functions
*/

#include "mysh.h"

void find_oldpwd(char ***env)
{
	int i = -1;
	bool is_old = false;

	while ((*env)[++i]) {
		if (!my_strncmp((*env)[i], "OLDPWD=", 7)
		&& (is_old = true) && chdir((*env)[i] + 7) == -1)
			write_err("cd: bad OLDPWD environnement\n");
	}
	if (!is_old)
		write_err("cd: no OLDPWD environnement\n");
}

void find_pwd(char ***env, list_t **path)
{
	char *cmd[3] = {"setenv", "PWD", NULL};
	char *old_cmd[3] = {"setenv", "OLDPWD", NULL};
	int size = 300;
	char *buffer = malloc(size);
	int i = -1;

	while ((*env)[++i]) {
		if (!my_strncmp((*env)[i], "PWD=", 4))
			old_cmd[2] = (*env)[i] + 4;
	}
	while (!getcwd(buffer, size)) {
		size += 200;
		free(buffer);
		buffer = malloc(size);
	}
	cmd[2] = buffer;
	my_setenv(cmd, env, path);
	my_setenv(old_cmd, env, path);
	free(buffer);
}
