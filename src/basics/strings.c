/*
** EPITECH PROJECT, 2017
** Project Minishell2
** File description:
** Description basics function
*/

#include "mysh.h"

int my_strlen(char *str)
{
	int i = -1;

	if (!str)
		return (0);
	while (str[++i]);
	return (i);
}

int my_putstr(char *str)
{
	int i = -1;

	while (str[++i])
		write(1, &str[i], 1);
	return (0);
}

int my_strcmp(char *s1, char *s2)
{
	int i = 0;

	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

int my_strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0')\
	&& n != 1) {
		i++;
		n--;
	}
	return (s1[i] - s2[i]);
}

int write_err(char *str)
{
	write(2, str, my_strlen(str));
	return (84);
}