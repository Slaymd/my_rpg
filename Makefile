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
				./src/NIK_LA_LIB/v_sync.c				\
				./src/lib.c				\
				./src/init.c				\
				./src/destroy.c				\
				./src/cycle/create.c			\
				./src/cycle/cycle.c			\
				./src/cycle/time.c			\
				./src/character/create.c		\
				./src/character/move.c			\
				./src/character/stat.c			\
				./src/character/display.c		\
				./src/particle/particle.c		\
				./src/particle/effect.c			\
				./src/particle/form.c			\
				./src/fairy/create.c			\
				./src/fairy/move.c			\
				./src/fairy/display.c			\
				./src/fairy/fight.c			\
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
				src/map/collision/tiles_collision.c	\
				src/ui/ui_basic_tools.c			\
				src/ui/ui_init_mainmenu.c		\
				src/ui/ui_events_mainmenu.c		\
				src/ui/ui_events_mapeditor.c		\
				src/ui/ui_init_mapeditor.c		\
				src/entity/disp_ennemy.c		\
				src/entity/ennemy_handling.c		\
				src/rand/rand.c				\
				src/entity/deplacement_stone_ogre.c	\
				src/entity/deplacement_ostrich.c	\
				src/game_loop.c				\
				src/entity/combat.c			\
				src/entity/ennemy_generation.c		\
				src/map/tile_getter.c			\
				src/map/generation/pos_gen.c		\
				src/map/generation/texture_table.c	\
				src/map/generation/texture_manager.c	\
				src/map/objects/init_objects.c	\
				src/map/objects/object_gen.c		\
				src/map/objects/object_disp.c		\
				src/entity/deplacement_lycan.c		\
<<<<<<< HEAD
				src/inventory/inventory.c		\
				src/inventory/fct_for_inventory.c
=======
				src/entity/boss.c			\
				src/inventaire/inventaire.c
>>>>>>> a055a1fac97a5ae4c48673c4c5a9270207ca465f

CFLAGS		=	-W -Wall -Wextra -I./include -g3 -lm

LIB			=	-L./lib/my -lmy -L./lib/list -llist -L./lib/ui -lui -lm

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

MAKE_LIBUI	=	make -C./lib/ui

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
	$(MAKE_LIBMY)
	$(MAKE_LIBLIST)
	$(MAKE_LIBUI)
	$(CC) $(OBJ) $(OBJ_MAIN) $(CFLAGS) $(LIB_EPICSFML) $(LIB) -o $(NAME)

my: $(OBJ)
	$(MAKE_LIBMY)
	$(MAKE_LIBLIST)
	$(MAKE_LIBUI)
	$(CC) $(OBJ) $(CFLAGS) $(LIB_CSFML) $(LIB) -o $(NAME)

$(TEST): $(OBJ) $(OBJ_TEST)
	$(MAKE_LIBMY)
	$(MAKE_LIBLIST)
	$(MAKE_LIBUI)
	$(CC) $(OBJ) $(OBJ_TEST) $(CFLAGS) $(CUNITTEST) $(LIB) -o $(TEST)

clean:
	rm -f $(OBJ_MAIN)
	rm -f $(OBJ)
	rm -f $(OBJ_TEST)
	$(MAKE_LIBMY) clean
	$(MAKE_LIBLIST) clean
	$(MAKE_LIBUI) clean

fclean:	clean
	rm -f $(NAME)
	rm -f $(TEST)
	$(MAKE_LIBMY) fclean
	$(MAKE_LIBLIST) fclean
	$(MAKE_LIBUI) fclean


re:	fclean all
