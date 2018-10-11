/*
** EPITECH PROJECT, 2017
** Project Minishell2
** File description:
** Description environment functions
*/

#include "mysh.h"

char **cp_env(char **env, char *l, int index, int st)
{
	int i = -1;
	int nb_word = 0;
	int w_len = 0;
	char **tmp = NULL;

	if (!(nb_word = 0) && !env)
		return (NULL);
	while (env[nb_word])
		++nb_word;
	nb_word += (l == NULL ? 0 : 1);
	if ((tmp = malloc(sizeof(char *) * (nb_word + 1))) == NULL)
		return (NULL);
	tmp[nb_word] = NULL;
	while (++i < nb_word) {
		w_len = (i == index ? my_strlen(l) : my_strlen(env[i + st]));
		if ((tmp[i] = malloc(sizeof(char) * (w_len + 1))) == NULL)
			return (NULL);
		if (i == index && !st && (st = -1))
			tmp[i] = my_strcpy(l, tmp[i]);
		else
			tmp[i] = my_strcpy(env[i + st], tmp[i]);
	}
	return (tmp);
}

void parse_env(char *line, list_t **path)
{
	int start = 5;
	int end = 4;

	while (line[++end]) {
		if (line[end] == ':') {
			add_element(path, line + start, end - start);
			start = end + 1;
		}
	}
	if (start != end)
		add_element(path, line + start, end - start);
}

void delete_line(char ***env, int index)
{
	int i = -1;
	int move = 0;

	while ((*env)[++i]) {
		if (i == index)
			move = 1;
		if (move)
			(*env)[i] = (*env)[i + 1];
	}
}
