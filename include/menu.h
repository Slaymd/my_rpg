/*
** EPITECH PROJECT, 2017
** matches
** File description:
** structs for graphical
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef _MENU_H_
	#define _MENU_H_

	typedef struct rpg_s rpg_t;
	typedef struct menu_s menu_t;
	typedef void (*button_action_t)(rpg_t *);

	typedef struct button_s {
		sfRectangleShape *rect;
		sfSprite *sprite;
		sfTexture *texture;
		int clicked;
		button_action_t callback;
	} button_t;

	typedef struct text_s {
		sfText *text;
		sfFont *font;
	} text_t;

	typedef struct scene_s {
		sfSprite *sprite;
		sfTexture *texture;
		button_t **button;
		text_t **text;
	} scene_t;

	struct menu_s {
		scene_t **scene;
		int state;
	};

	menu_t *create_menu(void);
	scene_t *create_start_scene();
	scene_t *create_menu_bg(char *path);
	button_t *create_menu_button(char *path, sfVector2f pos, sfVector2f size, button_action_t func);
	text_t *create_menu_text(char *info, int size, sfVector2f pos, sfColor color);
	void free_menu(menu_t *menu);
	void display_menu(scene_t *scene, window_t *window);

	//BUTTONS
	void manage_buttons(rpg_t *rpg);
	void quit_button(rpg_t *rpg);
	void play_button(rpg_t *rpg);
	void start_button(rpg_t *rpg);
	void options_button(rpg_t *rpg);

#endif
