/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** Header file
*/

#include "mysh.h"

int red_out(char *str, int end)
{
	char *tmp = filename(str, end);
	int fd = 0;
	int exist = (str[1] == '>' ? 0 : O_TRUNC);

	if (tmp == NULL)
		return (ERR_MALLOC);
	if ((fd = open(tmp, O_WRONLY | exist
	| O_APPEND | O_CREAT, 0644)) == -1) {
		write_err(tmp);
		free(tmp);
		return (write_err(": Permission denied\n"));
	}
	dup2(fd, 1);
	close(fd);
	free(tmp);
	return (0);
}

int red_din(char *str)
{
	char buffer[BUFFER_SIZE + 1];
	int rd = 0;
	int fd[2];

	if (pipe(fd) == -1)
		return (ERR_EXIT);
	buffer[0] = '\0';
	while (my_strcmp(buffer, str)) {
		if ((rd = read(0, buffer, BUFFER_SIZE)) < 0)
			return (write_err("Error with read\n"));
		if (rd)
			buffer[rd - 1] = '\0';
		if (my_strcmp(buffer, str)) {
			write(fd[1], buffer, my_strlen(buffer));
			write(fd[1], "\n", 1);
		}
	}
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	return (0);
}

int red_in(char *str, int end)
{
	char *tmp = filename(str, end);
	int fd = 0;

	if (tmp == NULL)
		return (ERR_MALLOC);
	if (str[1] == '<')
		return (red_din(tmp));
	if ((fd = open(tmp, O_RDONLY)) == -1) {
		write_err(tmp);
		free(tmp);
		return (write_err(": Permission denied\n"));
	}
	dup2(fd, 0);
	close(fd);
	free(tmp);
	return (0);
}
