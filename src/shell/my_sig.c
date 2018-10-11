/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** Main file.
*/

#include "mysh.h"

void put_error(int status)
{
	if (status == SEGFAULT) {
		my_putstr("Segmentation fault");
		(WCOREDUMP(status) ? my_putstr(" (core dumped)\n") :\
		my_putstr("\n"));
		signal_code(SEGFAULT);
	} else if (status == FLOATING) {
		my_putstr("Floating exception");
		(WCOREDUMP(status) ? my_putstr(" (core dumped)\n") :\
		my_putstr("\n"));
		signal_code(FLOATING);
	} else if (status == ABORT) {
		my_putstr("Abort");
		signal_code(ABORT);
	}
}

void my_jumper(char *cmd, int *i)
{
	while (cmd[*i] && is_separator(cmd[*i], "<> \t"))
		++(*i);
	while (cmd[*i] && !is_separator(cmd[*i], "<> \t"))
		++(*i);
}