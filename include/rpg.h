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
	#include <time.h>

	#include "map.h"
	#include "character.h"
	#include "fairy.h"
	#include "list.h"
	#include "my.h"
	#include "assets.h"
	#include "uilib.h"

	#define WIDTH 900
	#define HEIGHT 600

	#define SIZE_S_X 900
	#define SIZE_S_Y 600
	#define SIZE_I_X 1440
	#define SIZE_I_Y 1056

	typedef struct rpg_s rpg_t;
	typedef struct map_s map_t;
	typedef struct view_s view_t;

	#define V2F sfVector2f
	#define V2I sfVector2i
	#define FR sfFloatRect
	#define KeyPressed sfKeyboard_isKeyPressed

	// struct window_s {
	// 	sfRenderWindow *window;
	// 	sfVideoMode mode;
	// 	sfVector2f screen;
	// 	sfView *v_screen;
	// 	sfView *v_map;
	// 	sfSprite *sprite;
	// 	sfTexture *texture;
	// 	sfIntRect rect;
	// 	sfEvent event;
	// 	sfClock *clock;
	// 	sfTime time;
	// 	float seconds;
	// };

	struct view_s {
		sfView *v_screen;
		sfView *v_map;
		sfView *v_normal;
	};

	struct rpg_s {
		int state;
		sfRenderWindow *wd;
		sfEvent event;
		view_t *view;
		scene_t *scene;
		window_t *oldwin;
		map_t	*map;
		character_t *character;
		fairy_t *fairy;
		entity_t *ennemy[20];
		list_t *entities;
	};

	//WINDOW TOOLS
	sfRenderWindow	*create_window(void);

	//UI
	scene_t *init_mainmenu(rpg_t *rpg);
	scene_t *init_mapeditor(rpg_t *rpg);
	void disp_mainmenu(rpg_t *rpg);
	void swap_state_maptravelling(rpg_t *rpg);
	void regen_map_from_ui(void *data);

	//UI EVENTS
	void click_play_button(void *data);
	void click_save_button(void *data);

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
	void display_character(rpg_t *);
	void display_minimap(sfSprite *sprite, rpg_t *rpg);
	int disp_rect_at(sfRenderWindow *wd, map_t *mp,
	sfRectangleShape *rect, pos_t p);

	//MOVE
	void move_map(window_t *window, character_t *character);
	void move_character(character_t *character, rpg_t *rpg);

	//game_loop
	void menu(rpg_t *rpg);
	void game(rpg_t *rpg, map_t *map);

	//DESTROY
	void free_rpg(rpg_t *rpg);

	//ENNEMY
	int detect_ennemy(entity_t *ent, map_t *map);
	void follow_ogre(entity_t *ent, map_t *map);
	void follow_ostrich(entity_t *ent, map_t *map);
	void ennemy_handling(rpg_t *rpg, map_t *map);
	entity_t *add_ennemy_class_1(const char *path_sprite, sfIntRect square);
	void init_sprite(rpg_t *rpg);
	void display_ennemy(rpg_t *rpg, entity_t *ent, map_t *map, int);
	int rand_time(int min, int max);
	void deplacement_ogre(rpg_t *rpg, map_t *map, entity_t *ent);
	void deplacement_ostrich(rpg_t *rpg, map_t *map, entity_t *ent);
	void mirror_sprite(entity_t *ent, int mirror);

	//CHARACTER
	character_t *init_character(void);

	//FAIRY
	fairy_t *init_fairy(void);
	void display_fairy(rpg_t *rpg, sfEvent event);
	void move_fairy(fairy_t *fairy, rpg_t *rpg, sfEvent event);
	void fairy_fight(fairy_t *fairy, rpg_t *rpg);

#endif /* RPG_H_ */
