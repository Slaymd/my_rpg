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

	//#include "map.h"
	#include "character.h"
	#include "linked_list.h"

	#define WIDTH 800
	#define HEIGHT 600

	#define SIZE_S_X 750
	#define SIZE_S_Y 750
	#define SIZE_I_X 1440
	#define SIZE_I_Y 1056

	typedef struct rpg_s rpg_t;

	struct window_s {
		sfRenderWindow *window;
		sfVideoMode mode;
		sfVector2f screen;
		sfSprite *sprite;
		sfTexture *texture;
		sfIntRect rect;
		sfEvent event;
		sfClock *clock;
		sfTime time;
		float seconds;
	};

	struct rpg_s {
		//map_t	*map;
		window_t *window;
		character_t *character;
	};

	void event_gestion(window_t *window);

	//CREATE
	rpg_t *init_rpg(void);
	character_t *init_character(void);
	void set_window(window_t *window);
	window_t *init_window(void);

	//DISPLAY
	void display_map(window_t *window, character_t *character);
	void display_character(window_t *window, character_t *character);

	//MOVE
	void move_map(window_t *window, character_t *character);
	void move_character(character_t *character, window_t *window);

	//DESTROY
	void free_rpg(rpg_t *rpg);

#endif /* RPG_H_ */
