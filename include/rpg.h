/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** rpg header
*/

#ifndef __RPG_H__
	#define __RPG_H__

	#include <SFML/Graphics.h>
	#include <SFML/Audio.h>
	#include <math.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	#include <unistd.h>

	#include "map.h"
	#include "character.h"
	#include "list.h"
	#include "my.h"
	#include "assets.h"
	#include "menu.h"

	#define WIDTH 800
	#define HEIGHT 600

	#define SIZE_S_X 900
	#define SIZE_S_Y 600
	#define SIZE_I_X 1440
	#define SIZE_I_Y 1056

	typedef struct rpg_s rpg_t;
	typedef struct map_s map_t;

	struct window_s {
		sfRenderWindow *window;
		sfVideoMode mode;
		sfVector2f screen;
		sfView *v_screen;
		sfView *v_map;
		sfSprite *sprite;
		sfTexture *texture;
		sfIntRect rect;
		sfEvent event;
		sfClock *clock;
		sfTime time;
		float seconds;
	};

	struct rpg_s {
		int state;
		map_t	*map;
		window_t *window;
		menu_t *menu;
		character_t *character;
		list_t *entities;
	};


	//CREATE
	rpg_t *init_rpg(void);
	character_t *init_character(void);
	void set_window(window_t *window);
	window_t *init_window(void);

	//ACTION
	void verif_action(rpg_t *rpg);
	void event_gestion(window_t *window, map_t *map);

	//DISPLAY
	void display_map(window_t *window, character_t *character);
	void display_character(window_t *window, character_t *);
	void display_minimap(sfSprite *sprite, window_t *window);
	int disp_rect_at(sfRenderWindow *wd, map_t *mp,
	sfRectangleShape *rect, pos_t p);

	//MOVE
	void move_map(window_t *window, character_t *character);
	void move_character(character_t *character, window_t *window);

	//game_loop
	void menu(rpg_t *rpg);
	void game(rpg_t *rpg, map_t *map);

	//DESTROY
	void free_rpg(rpg_t *rpg);

	//ENNEMY
	void ennemy_handling(rpg_t *rpg, map_t *map);
	entity_t *add_ennemy_class_1(const char *path_sprite, sfIntRect square);
	void init_sprite(rpg_t *rpg);
	void display_ennemy(window_t *window, entity_t *ent, map_t *map, int);
	int rand_time(int min, int max);
	void deplacement_ogre(rpg_t *rpg, map_t *map, entity_t *ent);
	void deplacement_ostrich(rpg_t *rpg, map_t *map, entity_t *ent);
	void mirror_sprite(entity_t *ent, int mirror);

#endif /* RPG_H_ */
