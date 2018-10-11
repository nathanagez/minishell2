/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** Header file
*/

#include "mysh.h"

static int has_pipe_style(char **cmd_wpipe, char ***env, list_t **path, int i)
{
	char *tmp = NULL;

	if ((tmp = has_redirections(cmd_wpipe[i]))) {
		if (init_pipe(cmd_wpipe, i) == ERR_EXIT
		|| parent(tmp, env, path) == ERR_MALLOC)
			return (ERR_EXIT);
	}
	return (0);
}


int has_pipe(char *cmd, char ***env, list_t **path)
{
	int i = -1;
	int fds[2];
	char **cmd_wpipe = str_to_wordtab(cmd, "|");

	if (cmd_wpipe == NULL)
		return (ERR_MALLOC);
	while (cmd_wpipe[++i]) {
		fds[0] = dup(0);
		fds[1] = dup(1);
		if (has_pipe_style(cmd_wpipe, env, path, i) == ERR_EXIT)
			return(free_darray(cmd_wpipe));
		dup2(fds[0], 0);
		dup2(fds[1], 1);
	}
	free_darray(cmd_wpipe);
	return (0);
}

char *has_redirections(char *cmd)
{
	int i = 0;
	int j = -1;
	int k = -1;
	char *new_cmd = cmd;

	while (cmd[i]) {
		if (cmd[i] == '>' || cmd[i] == '<') {
			j = i;
			my_jumper(cmd, &i);
			k = i;
			if ((cmd[j] == '>' && red_out(cmd + j, k - j))
				|| (cmd[j] == '<' && red_in(cmd + j, k - j))
				|| !(new_cmd = get_cmd(new_cmd, cmd, j, k)))
				return (NULL);
		}
		if (cmd[i])
			++i;
	}
	return (new_cmd);
}
