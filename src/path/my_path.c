/*
** EPITECH PROJECT, 2017
** Project Minishell2
** File description:
** Description list functions
*/

#include "mysh.h"

list_t *new_element(char *path, int len)
{
	list_t *element = malloc(sizeof(*element));

	if (element == NULL)
		return (NULL);
	element->path = path;
	element->length = len;
	element->next = NULL;
	return (element);
}

void add_element(list_t **path, char *str, int len)
{
	list_t *element = new_element(str, len);
	list_t *tmp;

	if (!*path)
		*path = element;
	else {
		tmp = *path;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = element;
	}
}

list_t *get_path(char **env)
{
	int i = -1;
	list_t *path = NULL;

	while (env[++i]) {
		if (!my_strncmp(env[i], "PATH=", 5))
			parse_env(env[i], &path);
	}
	return (path);
}

char *concat_path(list_t *s1, char *s2, char separator)
{
	int i = 0;
	int j = -1;
	char *new_str = malloc((sizeof(char) * \
	(s1->length + my_strlen(s2) + 2)));

	if (!s2 || new_str == NULL)
		return (NULL);
	while (s1->path && i < s1->length) {
		new_str[i] = s1->path[i];
		++i;
	}
	new_str[i++] = separator;
	while (s2 && s2[++j])
		new_str[i + j] = s2[j];
	new_str[i + j] = '\0';
	return (new_str);
}