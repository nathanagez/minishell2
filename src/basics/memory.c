/*
** EPITECH PROJECT, 2018
** Project Minishell2
** File description:
** Memory management
*/

#include "mysh.h"

int free_darray(char **array)
{
	int i = -1;

	if (!array)
		return (ERR_EXIT);
	while (array[++i])
		free(array[i]);
	free(array);
	return (ERR_EXIT);
}

void free_tmpenv(char **tmp_env)
{
	int i = -1;

	while (tmp_env[++i]) {
		free (tmp_env[i]);
	}
	free (tmp_env);
}

int free_list(list_t *path, int is_child)
{
	list_t *tmp = path;

	while (tmp) {
		tmp = tmp->next;
		free(tmp);
	}
	if (!is_child)
		my_putstr("exit\n");
	return (0);
}
