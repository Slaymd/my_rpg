##
## EPITECH PROJECT, 2018
## PSU_minishell2_2017
## File description:
## MF
##

SRC_MAIN	=	src/main.c

SRC_TEST	=	\

SRC		=	\

CFLAGS	=	-W -Wall -Wextra -I./include -L./lib/my -lmy -g3

CUNITTEST	=	-lcriterion

OBJ		=	$(SRC:.c=.o)

OBJ_MAIN	=	$(SRC_MAIN:.c=.o)

OBJ_TEST	=	$(SRC_TEST:.c=.o)

NAME		=	mysh

TEST		=	test

MAKE_LIB	=	make -C./lib/my

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
	$(MAKE_LIB)
	gcc $(OBJ) $(OBJ_MAIN) $(CFLAGS) -o $(NAME)

$(TEST): $(OBJ) $(OBJ_TEST)
	$(MAKE_LIB)
	gcc $(OBJ) $(OBJ_TEST) $(CFLAGS) $(CUNITTEST) -o $(TEST)

clean:
	rm -f $(OBJ_MAIN)
	rm -f $(OBJ)
	rm -f $(OBJ_TEST)
	$(MAKE_LIB) clean

fclean:	clean
	rm -f $(NAME)
	rm -f $(TEST)
	$(MAKE_LIB) fclean

re:	fclean all
