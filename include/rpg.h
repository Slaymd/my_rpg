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
	#include "htp.h"
	#include "matchstick.h"
	#include "npc.h"
	#include "cycle.h"
	#include "character.h"
	#include "particle.h"
	#include "fairy.h"
	#include "list.h"
	#include "my.h"
	#include "assets.h"
	#include "uilib.h"
	#include "inventory.h"

	#define WIDTH 900
	#define HEIGHT 600

	#define ZOOM 0.8

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
	#define IR sfIntRect
	#define KeyPressed sfKeyboard_isKeyPressed

	struct view_s {
		sfView *v_screen;
		sfView *v_map;
		sfView *v_normal;
	};

	struct rpg_s {
		int state;
		sfRenderWindow *wd;
		sfEvent event;
		sfMusic *music;
		view_t *view;
		npc_t *npc;
		htp_t *htp;
		cycle_t *cycle;
		scene_t *scene;
		window_t *oldwin;
		map_t	*map;
		character_t *character;
		fairy_t *fairy;
		entity_t *ennemy[20];
		inv_t *inv;
		item_t *slot[20];
		list_t *entities;
	};

	//WINDOW TOOLS
	sfRenderWindow	*create_window(void);

	//SWITCH SCENE EVENTS
	int pause_screen_events(rpg_t *rpg, sfEvent event);

	//UI
	scene_t *init_mainmenu(rpg_t *rpg);
	scene_t *init_mapeditor(rpg_t *rpg);
	scene_t *init_pausescreen(rpg_t *rpg);
	void disp_mainmenu(rpg_t *rpg);
	int disp_pause_screen(rpg_t *rpg, int ignore_state);
	void swap_state_maptravelling(rpg_t *rpg);
	void regen_map_from_ui(void *data);

	//UI EVENTS
	void click_play_button(void *data);
	void click_save_button(void *data);
	void click_map_settings_button(void *data);
	void click_exit_button(void *data);
	void click_pause_resume_button(void *data);
	void click_pause_menu_button(void *data);
	void click_pause_exit_button(void *data);
	void click_how_to_play_button(void *data);
	void click_vsync_button(void *data);

	//SYS IMPROVEMENTS
	void set_v_sync(rpg_t *rpg);

	//CREATE
	rpg_t *init_rpg(void);
	character_t *init_character(void);
	void set_window(window_t *window);
	window_t *init_window(void);

	//INVENTAIRE
	void init_inv(rpg_t *rpg);
	void init_tab_item(rpg_t *rpg);
	void inventory(rpg_t *rpg);
	void unequip(item_t *slot, item_t **inv);
	void equip(item_t *slot, item_t **inv);
	void fill_slot(item_t *slot1, item_t *slot2, int i_equip);
	int if_m_in_sprite(sfVector2i pos_m, item_t **slot);
	void draw_all(rpg_t *rpg);
	text_t *create_inv_text(char *info, int size, sfVector2f pos,
	sfColor color);
	void recup_info(inv_t *inv, main_stat_t *stat);
	void consom(item_t *slot, rpg_t *rpg);
	void rand_drop_item(rpg_t *rpg, entity_t *ent);
	void fill_r_life(inv_t *inv);
	void fill_r_life2(inv_t *inv);
	void fill_r_mana(inv_t *inv);
	void fill_r_mana2(inv_t *inv);
	void fill_att(inv_t *inv);
	void fill_att2(inv_t *inv);
	void fill_life_potion(inv_t *inv);
	void fill_mana_potion(inv_t *inv);

	//ACTION
	void verif_action(rpg_t *rpg);
	void event_gestion(window_t *window, map_t *map);

	//DISPLAY
	void display_map(window_t *window, character_t *character);
	void display_character(rpg_t *, character_t *character);
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
	void xp_ostrich(entity_t *ent, rpg_t *rpg);
	int chunk_entities_gen_villager2(map_t *map, pos_t apos);
	int chunk_entities_gen_villager3(map_t *map, pos_t apos);
	void deplacement_villager2(rpg_t *rpg, map_t *map, entity_t *ent);
	void deplacement_villager3(rpg_t *rpg, map_t *map, entity_t *ent);
	void mirror_ogre(entity_t *ent, int mirror);
	int go_left_ogre(entity_t *ent, int count, map_t *map, rpg_t *rpg);
	int go_right_ogre(entity_t *ent, int count, map_t *map, rpg_t *rpg);
	int my_if_ogre(entity_t *ent, int x);
	void dead_ogre(entity_t *ent, rpg_t *rpg);
	void lycan_die(entity_t *ent, rpg_t *rpg);
	int run_char(entity_t *ent, map_t *map, int xx, int yy);
	int detect_attack_char(entity_t *ent, map_t *map);
	int detect_villager(entity_t *ent, map_t *map);
	void attack_ogre(entity_t *ent, rpg_t *rpg);
	int go_left_lycan(entity_t *ent, int count, map_t *map);
	int go_right_lycan(entity_t *ent, int count, map_t *map);
	int my_if_lycan(entity_t *ent, int x);
	void attack_lycan(entity_t *ent, rpg_t *rpg);
	void deplacement_villager(rpg_t *rpg, map_t *map, entity_t *ent);
	void lycan_cry(rpg_t *rpg, entity_t *ent, int count);
	void follow_lycan(entity_t *ent, map_t *map, rpg_t *rpg, int first);
	void deplacement_lycan(rpg_t *rpg, map_t *map, entity_t *ent);
	int detect_ennemy(entity_t *ent, map_t *map);
	void follow_ogre(entity_t *ent, map_t *map, rpg_t *rpg);
	void follow_ostrich(entity_t *ent, map_t *map);
	void ennemy_handling(rpg_t *rpg, map_t *map);
	entity_t *add_ennemy_class_1(const char *path_sprite, sfIntRect square);
	void init_sprite(rpg_t *rpg);
	void display_ennemy(rpg_t *rpg, entity_t *ent, map_t *map, int);
	int rand_time(int min, int max);
	void deplacement_ogre(rpg_t *rpg, map_t *map, entity_t *ent);
	void deplacement_ostrich(rpg_t *rpg, map_t *map, entity_t *ent);
	void mirror_sprite(entity_t *ent, int mirror);
	void reinit_var(rpg_t *rpg, entity_t *ent, map_t *map);
	entity_t *create_entity(map_t *map, entity_type type);

	//CHARACTER
	character_t *init_character(void);

	//FAIRY
	fairy_t *init_fairy(void);
	void display_fairy(rpg_t *rpg, sfEvent event);
	void move_fairy(fairy_t *fairy, rpg_t *rpg, sfEvent event);
	void fairy_fight(fairy_t *fairy, rpg_t *rpg);
	void new_shoot(list_shoot_t *list, pos_t pos_e,
	pos_t pos_r, rpg_t *rpg);
	void end_shoot(list_shoot_t *list);

#endif /* RPG_H_ */
