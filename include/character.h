/*
** EPITECH PROJECT, 2017
** matches
** File description:
** structs for graphical
*/

#ifndef _CHARACTER_H_
	#define _CHARACTER_H_

	#define SIZE_C_X 68
	#define SIZE_C_Y 72

	typedef struct window_s window_t;
	typedef struct character_s character_t;

	struct character_s {
		sfSprite *sprite;
		sfTexture *texture;
		sfIntRect rect;
		sfClock *clock;
		sfTime time;
		float seconds;
		sfVector2f pos_screen;
		pos_t pos;
		int speed;
	};

#endif
