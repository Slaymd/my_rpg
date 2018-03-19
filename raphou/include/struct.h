/*
** EPITECH PROJECT, 2017
** matches
** File description:
** structs for graphical
*/

#ifndef _STRUCT_H_
	#define _STRUCT_H_

	typedef struct window_s {
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
	} window_t;

	typedef struct character_s {
		sfSprite *sprite;
		sfTexture *texture;
		sfIntRect rect;
	} character_t;

#endif
