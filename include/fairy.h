/*
** EPITECH PROJECT, 2017
** matches
** File description:
** structs for graphical
*/

#ifndef _FAIRY_H_
	#define _FAIRY_H_

	#define SIZE_F_X 34
	#define SIZE_F_Y 49
	#define MOVE_F_X 100
	#define MOVE_F_Y 100

	typedef struct fairy_s fairy_t;

	struct fairy_s {
		sfSprite *sprite;
		sfTexture *texture;
		sfIntRect rect;
		sfClock *clock;
		sfTime time;
		float seconds;
		sfVector2f pos;
		sfVector2f kinetic;
	};

#endif
