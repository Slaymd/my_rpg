/*
** EPITECH PROJECT, 2017
** matches
** File description:
** structs for graphical
*/

#ifndef _CYCLE_H_
	#define _CYCLE_H_

	typedef struct cycle_s cycle_t;

	struct cycle_s {
		int h;
		int m;
		sfFont *font;
		sfText *text;
		sfClock *clock;
		sfTime time;
		float seconds;
		sfSprite *sprite;
		sfTexture *texture;
	};

	//CREATE
	cycle_t *create_cycle(void);

	//CYCLE
	void cycle_handler(rpg_t *rpg);
	void run_cycle(rpg_t *rpg);

	//TIME
	void display_time(cycle_t *cycle, sfRenderWindow *window);
	void refresh_time(cycle_t *cycle, rpg_t *rpg);
#endif
