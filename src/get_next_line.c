/*
** EPITECH PROJECT, 2017
** get_nextline
** File description:
** GNL function
*/

#include "mysh.h"

char *my_gnlrealloc(char *src, int n)
{
	char *result = malloc(sizeof(char) * (n + 1));
	unsigned int j = 0;

	if (result == NULL)
		return (NULL);
	while (n > 0) {
		result[j] = src[j];
		n = n - 1;
		j = j + 1;
	}
	free(src);
	return (result);
}

int return_buffer(int fd, char *str)
{
	static int i = 0;
	static char buff[READ_SIZE];
	static int n = READ_SIZE;

	if (i >= n || i == 0) {
		i = 0;
		if ((n = read(fd, buff, READ_SIZE)) < 0 || fd < 0)
			return (0);
	}
	if (n == 0) {
		*str = '\0';
	} else {
		if (buff[i] == '\n')
			*str = '\0';
		else
			*str = buff[i];
		i = i + 1;
	}
	return (n);
}

char *get_next_line(int fd)
{
	char *line = malloc(sizeof(char) * (READ_SIZE + 1));
	unsigned int i = 0;
	int n = return_buffer(fd, &line[i]);

	if (line == NULL)
		return (NULL);
	if (fd < 0 || n == 0) {
		free(line);
		return (NULL);
	}
	while (line[i] != '\0') {
		line = my_gnlrealloc(line, i + READ_SIZE + 1);
		n = return_buffer(fd, &line[++i]);
	}
	line[i] = '\0';
	return (line);
}
