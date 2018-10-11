/*
** EPITECH PROJECT, 2017
** Project Minishell2
** File description:
** Description header file
*/

#ifndef _MACROS_H_
# define _MACROS_H_
# define RUN (42)
# define ERR_EXIT (84)
# define ERR_MALLOC (84)
# define READ_SIZE (1)
# define ABORT (134)
# define FLOATING (136)
# define SEGFAULT (139)
# define BUFFER_SIZE (1024)

typedef struct list_s {
	char *path;
	int length;
	struct list_s *next;
} list_t;

typedef struct builtin_s {
	char *name;
	void (*fct)(char **, char ***, list_t **);
} builtin_t;

typedef enum bool {
	false,
	true
} bool;

#endif