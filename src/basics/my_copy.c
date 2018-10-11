/*
** EPITECH PROJECT, 2017
** Project Minishell2
** File description:
** Description basics function
*/

#include "mysh.h"

char *my_catsep(char *s1, char *s2, char sep)
{
	int i = -1;
	int j = -1;
	char *tmp = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 2));

	if (tmp == NULL)
		return (NULL);
	while (s1 && s1[++i])
		tmp[i] = s1[i];
	tmp[i] = sep;
	++i;
	while (s2 && s2[++j])
		tmp[i + j] = s2[j];
	j = (j == -1 ? 0 : j);
	tmp[i + j] = 0;
	return (tmp);
}

char *my_strcpy(char *src, char *dest)
{
	int i = -1;

	while (src[++i])
		dest[i] = src[i];
	return (dest);
}

char *filename(char *str, int index)
{
	int i = 0;
	int j = 0;
	char *tmp = NULL;

	while (str[i] && is_separator(str[i], "<> \t"))
		++i;
	tmp = malloc(sizeof(char) * index - i + 1);
	if (tmp == NULL)
		return (NULL);
	tmp[index - i] = 0;
	j = 0;
	while (str[i] && !is_separator(str[i], "<> \t"))
		tmp[j++] = str[i++];
	return (tmp);
}

void my_cd_style(char ***env, int i)
{
	if (!my_strncmp((*env)[i], "HOME=", 5) && chdir((*env)[i] + 5) == -1)
		write_err("cd: No home directory\n");
}