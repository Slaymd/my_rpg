##
## EPITECH PROJECT, 2018
## PSU_my_rpg_2017
## File description:
## MF
##

SRC_MAIN		=	src/main.c

SRC_TEST		=	\

SRC			=	./src/main.c					\
				./src/init.c					\
				./src/move.c					\
				./src/event.c					\
				./src/display.c				\
				./src/destroy.c				\
				src/map/init_map.c				\
				src/map/disp_map.c				\
				src/map/pos_tools.c				\
				src/map/chunk_getter.c			\
				src/map/init_textures.c			\
				src/map/sprite_getter.c			\
				src/event/events_handler.c		\
				src/list/linked_list_tools.c		\
				src/map/generation/map_gen.c		\
				src/map/generation/tile_gen.c		\
				src/map/generation/chunk_gen.c	\
				src/map/generation/perlin_noise.c	\

CFLAGS		=	-W -Wall -Wextra -I./include -L./lib/my -lmy -g3 -lm

LIB_TEST		=	-lcriterion

LIB_CSFML		=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

LIB_EPICSFML	=	-lc_graph_prog

OBJ			=	$(SRC:.c=.o)

OBJ_MAIN		=	$(SRC_MAIN:.c=.o)

OBJ_TEST		=	$(SRC_TEST:.c=.o)

NAME			=	my_rpg

TEST			=	test

MAKE_LIB		=	make -C./lib/my

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
	$(MAKE_LIB)
	gcc $(OBJ) $(OBJ_MAIN) $(CFLAGS) $(LIB_EPICSFML) -o $(NAME)

my: $(OBJ)
	$(MAKE_LIB)
	gcc $(OBJ) $(CFLAGS) $(LIB_CSFML) -o $(NAME)

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
