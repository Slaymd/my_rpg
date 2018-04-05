##
## EPITECH PROJECT, 2018
## PSU_my_rpg_2017
## File description:
## MF
##

CC			=	gcc

SRC_MAIN		=	src/main.c

SRC_TEST		=	\

SRC			=	./src/main.c				\
				./src/lib.c				\
				./src/init.c				\
				./src/destroy.c				\
				./src/character/move.c			\
				./src/character/display.c		\
				src/map/init_map.c			\
				src/map/disp_map.c			\
				src/map/pos_tools.c			\
				src/map/chunk_getter.c			\
				src/map/init_textures.c			\
				src/map/sprite_getter.c			\
				src/event/events_gestion.c		\
				src/map/generation/map_gen.c		\
				src/map/generation/tile_gen.c		\
				src/map/generation/chunk_gen.c		\
				src/map/generation/perlin_noise.c	\
				src/ennemy/ennemy_generation.c		\
				./src/menu/create.c			\
				./src/menu/display.c			\
				./src/menu/free.c			\
				./src/menu/scenes/scene_start.c		\
				./src/menu/scenes/scene_options.c	\
				./src/menu/buttons/manage_buttons.c	\
				./src/menu/buttons/buttons_main.c	\
				./src/menu/buttons/buttons_scene.c

CFLAGS		=	-W -Wall -Wextra -I./include -g3 -lm

LIB			=	-L./lib/my -lmy -L./lib/list -llist

LIB_TEST		=	-lcriterion

LIB_CSFML		=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

LIB_EPICSFML	=	-lc_graph_prog

OBJ			=	$(SRC:.c=.o)

OBJ_MAIN		=	$(SRC_MAIN:.c=.o)

OBJ_TEST		=	$(SRC_TEST:.c=.o)

NAME			=	my_rpg

TEST			=	test

MAKE_LIBMY	=	make -C./lib/my

MAKE_LIBLIST	=	make -C./lib/list

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
	$(MAKE_LIBMY)
	$(MAKE_LIBLIST)
	$(CC) $(OBJ) $(OBJ_MAIN) $(CFLAGS) $(LIB_EPICSFML) $(LIB) -o $(NAME)

my: $(OBJ)
	$(MAKE_LIBMY)
	$(MAKE_LIBLIST)
	$(CC) $(OBJ) $(CFLAGS) $(LIB_CSFML) $(LIB) -o $(NAME)

$(TEST): $(OBJ) $(OBJ_TEST)
	$(MAKE_LIBMY)
	$(MAKE_LIBLIST)
	$(CC) $(OBJ) $(OBJ_TEST) $(CFLAGS) $(CUNITTEST) $(LIB) -o $(TEST)

clean:
	rm -f $(OBJ_MAIN)
	rm -f $(OBJ)
	rm -f $(OBJ_TEST)
	$(MAKE_LIBMY) clean
	$(MAKE_LIBLIST) clean

fclean:	clean
	rm -f $(NAME)
	rm -f $(TEST)
	$(MAKE_LIBMY) fclean
	$(MAKE_LIBLIST) fclean

re:	fclean all
