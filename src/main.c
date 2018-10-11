/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** Header file
*/

#include "mysh.h"

int signal_code(int code)
{
	static int i = 0;

	if (code == 0)
		return (i);
	i = code;
	return (i);
}

void my_ctrl_c(__attribute__((unused))int empty)
{
	my_putstr("\n$> ");
}

int main(__attribute__((unused))int ac,
__attribute__((unused))char **av, char **env)
{
	char **tmp_env = cp_env(env, NULL, -1, 0);
	list_t *path = NULL;

	if (tmp_env == NULL)
		return (ERR_EXIT);
	path = get_path(tmp_env);
	signal(2, my_ctrl_c);
	prompt(&path, &tmp_env);
	free_darray(tmp_env);
	return (signal_code(0));
}

int prompt(list_t **path, char ***env)
{
	char *command = NULL;

	while (RUN) {
		if (isatty(0) == 1)
			my_putstr("$> ");
		command = get_next_line(0);
		if (command == NULL) {
			my_putstr(isatty(0) == 1 ? "exit\n" : "\0");
			return (free_list(*path, 0));
		}
		if (command_parser(command, env, path) == ERR_MALLOC)
			return (free_list(*path, 1));
	}
	free(command);
	return (0);
}