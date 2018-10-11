/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** Header file
*/

#include "mysh.h"

int check_is_dir(char *path)
{
	struct stat file;

	lstat(path, &file);
	if (S_ISDIR(file.st_mode) == 1)
		return (0);
	return (ERR_EXIT);
}

static int check_access_style(char *path)
{
	if (access(path, R_OK) == 0) {
		if (check_is_dir(path) == ERR_EXIT) {
			my_putstr(path);
			my_putstr(": Not a directory.\n");
			return (ERR_EXIT);
		}
		chdir(path);
		return (0);
	}
	return (0);
}

int check_access(char *path)
{
	if (access(path, F_OK) == 0) {
		if (check_access_style(path) == ERR_EXIT)
			return (ERR_EXIT);
		my_putstr(path);
		my_putstr(": Permission denied.\n");
		return (ERR_EXIT);
	}
	my_putstr(path);
	my_putstr(": No such file or directory.\n");
	return (ERR_EXIT);
}