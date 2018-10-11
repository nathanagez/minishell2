##
## EPITECH PROJECT, 2018
## Project mysh
## File description:
## Build mysh binary.
##

SRC	=	src/main.c	\
		src/get_next_line.c	\
		src/basics/memory.c	\
		src/basics/str_to_wordtab.c	\
		src/basics/strings.c	\
		src/environment/my_env.c	\
		src/path/my_path.c	\
		src/path/my_cd.c	\
		src/shell/my_parser.c	\
		src/shell/my_checker.c	\
		src/shell/my_builtin.c	\
		src/shell/my_pipes.c	\
		src/shell/my_redirections.c	\
		src/shell/my_cd_check.c	\
		src/basics/my_copy.c	\
		src/shell/my_sig.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-Werror -Wextra -W -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable -I ./include/

CC	=	gcc

RM	=	rm -f

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
