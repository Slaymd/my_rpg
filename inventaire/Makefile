##
## EPITECH PROJECT, 2017
## makefile
## File description:
## makefile
##

SRC	=	inventaire.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I include/

NAME	=	rpg

all:	$(NAME)

$(NAME):	$(OBJ)
	 gcc -o $(NAME) $(CFLAGS) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfm\
l-audio -lcsfml-system

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f *~
	rm -f libmy.a

re:	fclean all
