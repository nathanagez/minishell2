/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** Header file
*/

#include "mysh.h"

int exec_cmd(char *cmd, char **env, list_t *path)
{
	list_t	*tmp = path;
	char *cmd_line = NULL;
	char **commands = str_to_wordtab(cmd, " \t");
	int exec_err = 0;
	struct stat st;

	if (commands == NULL)
		return (ERR_MALLOC);
	exec_err = (execve(commands[0], commands, env) != -1 ? 1 : 0);
	while (tmp && !exec_err) {
		cmd_line = concat_path(tmp, commands[0], '/');
		if (lstat(cmd_line, &st) != -1)
			execve(cmd_line, commands, env);
		free(cmd_line);
		tmp = tmp->next;
	}
	write_err(commands[0]);
	write_err(": Command not found.\n");
	return (free_darray(commands));
}

char *get_cmd(char *cmd, char *cmdref, int start, int end)
{
	int i = -1;
	int j = -1;
	char *new_cmd = malloc(my_strlen(cmd) - (end - start) + 1);

	if (new_cmd == NULL)
		return (NULL);
	while (cmd[++i] && !is_separator(cmd[i], "<>"))
		new_cmd[i] = cmd[i];
	j = i + end - start;
	while (cmd[j])
		new_cmd[i++] = cmd[j++];
	new_cmd[i] = 0;
	if (cmd != cmdref)
		free(cmd);
	return (new_cmd);
}

int parent(char *cmd, char ***env, list_t **path)
{
	pid_t pid;
	int status = 0;

	if ((status = is_builtin(cmd, env, path)))
		return (status);
	if ((pid = fork()) == -1)
		return (ERR_EXIT);
	if (pid > 0) {
		if (wait(&status) == -1)
			return (ERR_EXIT);
		put_error(status);
	}
	else
		return (exec_cmd(cmd, *env, *path));
	return (0);
}

int command_parser(char *gnl, char ***env, list_t **path)
{
	int i = -1;
	char **cmd = str_to_wordtab(gnl, ";");

	if (cmd == NULL)
		return (ERR_MALLOC);
	while (cmd[++i]) {
		if (has_pipe(cmd[i], env, path) == ERR_MALLOC)
			return (free_darray(cmd));
	}
	free_darray(cmd);
	return (0);
}