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

	typedef struct character_s character_t;
	typedef struct main_stat_s main_stat_t;

	struct main_stat_s {
		float hp;
		float mana;
		float xp;
		float crit;
	};

	struct character_s {
		sfSprite *sprite;
		sfTexture *texture;
		sfIntRect rect;
		sfClock *clock;
		sfTime time;
		float seconds;
		int speed;
		sfVector2f pos_screen;
		pos_t pos;
		main_stat_t *stat;
		sfRectangleShape *hp_bar;
		sfRectangleShape *mana_bar;
	};

#endif
