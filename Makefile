##
## EPITECH PROJECT, 2018
## PSU_my_rpg_2017
## File description:
## MF
##

CC			=	gcc

SRC_TEST		=	\

SRC			=	src/main.c				\
				src/settings/v_sync.c			\
				src/lib.c				\
				src/init.c				\
				src/destroy.c				\
				src/cycle/create.c			\
				src/cycle/cycle.c			\
				src/cycle/time.c			\
				src/cycle/destroy.c			\
				src/character/create.c			\
				src/character/move.c			\
				src/character/stat.c			\
				src/character/display.c			\
				src/particle/particle.c			\
				src/particle/effect.c			\
				src/particle/form.c			\
				src/npc/create.c			\
				src/npc/inter.c				\
				src/npc/game.c				\
				src/npc/math.c				\
				src/npc/fear.c				\
				src/npc/destroy.c			\
				src/npc/display.c			\
				src/htp/create.c			\
				src/htp/htp.c				\
				src/htp/destroy.c			\
				src/fairy/create.c			\
				src/fairy/move.c			\
				src/fairy/display.c			\
				src/fairy/fight.c			\
				src/map/init_map.c			\
				src/map/disp_map.c			\
				src/map/pos_tools.c			\
				src/map/chunk_getter.c			\
				src/map/init_textures.c			\
				src/map/sprite_getter.c			\
				src/event/events_gestion.c		\
				src/event/event_scene_switchs.c		\
				src/map/generation/map_gen.c		\
				src/map/generation/tile_gen.c		\
				src/map/generation/chunk_gen.c		\
				src/map/generation/perlin_noise.c	\
				src/map/collision/tiles_collision.c	\
				src/ui/ui_basic_tools.c			\
				src/ui/ui_init_mainmenu.c		\
				src/ui/ui_events_mainmenu.c		\
				src/ui/ui_events_mapeditor.c		\
				src/ui/ui_events_pause.c		\
				src/ui/ui_init_mapeditor.c		\
				src/ui/ui_init_pause.c			\
				src/entity/disp_ennemy.c		\
				src/entity/ennemy_handling.c		\
				src/rand/rand.c				\
				src/entity/deplacement_stone_ogre.c	\
				src/entity/deplacement_ostrich.c	\
				src/entity/combat.c			\
				src/entity/ennemy_generation.c		\
				src/map/tile_getter.c			\
				src/map/generation/pos_gen.c		\
				src/map/generation/texture_table.c	\
				src/map/generation/texture_manager.c	\
				src/map/objects/init_objects.c		\
				src/map/objects/object_gen.c		\
				src/map/objects/object_disp.c		\
				src/map/free/free_map.c			\
				src/map/free/free_chunk.c		\
				src/map/free/free_object.c		\
				src/map/free/free_texture.c		\
				src/entity/deplacement_lycan.c		\
				src/entity/boss.c			\
				src/inventory/inventory.c		\
				src/inventory/fct_for_inventory.c	\
				src/inventory/fct_for_inventory2.c	\
				src/inventory/init_inventory.c		\
				src/inventory/init_tab_inventory.c	\
				src/inventory/rand_drop_item.c		\
				src/inventory/drop_item.c		\
				src/inventory/drop_item2.c		\
				src/entity/deplacement_villager.c	\
				src/matchstick/main.c			\
				src/matchstick/init.c			\
				src/matchstick/ai.c			\
				src/matchstick/display_match.c		\
				src/matchstick/player.c			\
				src/matchstick/event_end_error.c	\
				src/entity/boss_deg.c			\
				src/entity/dead.c			\
				src/entity/stone_ogre_capacity.c	\
				src/map/generation/func_chunk_gen.c

CFLAGS		=	-W -Wall -Wextra -I./include

LIB			=	-L./lib/my -lmy -L./lib/list -llist -L./lib/ui -lui -lm

LIB_TEST		=	-lcriterion

LIB_CSFML		=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

LIB_EPICSFML		=	-lc_graph_prog

OBJ			=	$(SRC:.c=.o)

OBJ_TEST		=	$(SRC_TEST:.c=.o)

NAME			=	my_rpg

TEST			=	test

MAKE_LIBMY	=	make -C./lib/my

MAKE_LIBLIST	=	make -C./lib/list

MAKE_LIBUI	=	make -C./lib/ui

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE_LIBMY)
	$(MAKE_LIBLIST)
	$(MAKE_LIBUI)
	$(CC) $(OBJ) $(CFLAGS) $(LIB_EPICSFML) $(LIB) -o $(NAME)

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
