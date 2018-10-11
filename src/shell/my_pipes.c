/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** Header file
*/

#include "mysh.h"

int init_pipe(char **cmd_pipe, int i)
{
	static int fdpipe[2];
	int fd = 0;

	if (i)
		fd = fdpipe[0];
	if (pipe(fdpipe) == -1)
		return (ERR_EXIT);
	if (cmd_pipe[i + 1]) {
		dup2(fdpipe[1], 1);
		close(fdpipe[1]);
	}
	dup2(fd, 0);
	return (0);
}
