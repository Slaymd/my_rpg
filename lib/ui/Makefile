##
## EPITECH PROJECT, 2017
## makefile
## File description:
## lib maker :o
##

CC		=	gcc

CFLAGS	=	-Wall -Wextra -W

SRC		=	$(wildcard *.c)

OBJ		=	$(SRC:.c=.o)

NAME 	=	libui.a

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc libmy.a $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
