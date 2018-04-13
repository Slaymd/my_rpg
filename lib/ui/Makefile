##
## EPITECH PROJECT, 2017
## makefile
## File description:
## lib maker :o
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

all:	make_lib clean

make_lib:	$(OBJ)
	ar rc libui.a *.o

clean:
	rm *.o
