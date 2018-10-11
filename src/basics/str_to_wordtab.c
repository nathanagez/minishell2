/*
** EPITECH PROJECT, 2018
** Project Minishell2
** File description:
** str_to_wordtab function
*/

#include "mysh.h"

bool is_separator(char c, char *separator)
{
	int i = -1;

	while (separator[++i])
		if (c == separator[i])
			return (true);
	return (false);
}

int words_number(char *str, char *separator)
{
	unsigned int i = 0;
	unsigned int words = 0;

	if (!str)
		return (ERR_EXIT);
	while (str[i]) {
		while (str[i] && is_separator(str[i], separator))
			++i;
		if (str[i])
			++words;
		while (str[i] && !is_separator(str[i], separator))
			++i;
		if (str[i])
			++i;
	}
	return (words);
}

int word_length(char *str, char *separator)
{
	unsigned int i = 0;

	while (str[i] && !is_separator(str[i], separator))
		++i;
	return (i);
}

char **str_to_wordtab(char *str, char *separator)
{
	int i = -1;
	unsigned int j = 0;
	unsigned int pos = 0;
	int words = words_number(str, separator);
	char **tab = malloc(sizeof(char *) * (words + 1));

	if (tab == NULL)
		return (NULL);
	tab[words] = NULL;
	while (++i < words) {
		while (str[pos] && is_separator(str[pos], separator))
			++pos;
		tab[i] = malloc(word_length(str + pos, separator) + 1);
		if (tab[i] == NULL)
			return (NULL);
		j = 0;
		while (str[pos] && !is_separator(str[pos], separator))
			tab[i][j++] = str[pos++];
		tab[i][j] = '\0';
	}
	return (tab);
}
