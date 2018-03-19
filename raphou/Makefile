##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## make
##

CC		=	gcc

SRC		= 	./src/main.c	\
			./src/event.c	\
			./src/init.c	\
			./src/display.c	\
			./src/destroy.c	\
			./src/move.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-W -Wall -Wextra -g3 -I ./include

LIB		=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -lm

#LIB		=	-lc_graph_prog

NAME		=	rafou

all:		$(NAME)


$(NAME):	$(OBJ)
		gcc $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re: 		fclean all
