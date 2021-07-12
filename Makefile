##
## EPITECH PROJECT, 2020
## mk
## File description:
## mk
##

SRC	=	src/main.c		\
		src/my_line.c		\
		src/my_str_cft.c	\
		src/minishell.c		\
		src/my_env.c		\
		src/str_to_arr.c	\
		src/check_env.c		\
		src/execve.c		\
		src/my_cd.c		\
		src/strcpy.c		\
		src/pipe.c		\
		src/redir.c		\
		src/init_entries.c	\
		src/entries.c		\
		src/entrie_two.c		\
		src/my_echo.c		\
		src/utils.c		\
		src/utils_two.c

SRC_TEST	=	unit_tests/test_lib.c \
			src/strcpy.c	\
			src/str_to_arr.c	\
			src/my_str_cft.c	\

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f
CFLAGS	+=	-I./include/ -L./ -Wall -Wextra
LDFLAGS	=	--coverage -lcriterion
DEBUG	=	-g3

NAME	=	42sh	\

TEST_NAME	=	unitest

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(DEBUG) $(CFLAGS) $(SRC)

.PHONY: clean fclean re

clean:
	$(RM) $(OBJ)
	$(RM) *.gcno
	$(RM) *.gcda

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)

unitest	:
		gcc -o $(TEST_NAME) $(SRC_TEST) $(LDFLAGS) $(CFLAGS)

tests_run: fclean unitest
		./unitest
	gcovr --exclude tests/ --branches
	gcovr --exclude tests/

re:     fclean all
