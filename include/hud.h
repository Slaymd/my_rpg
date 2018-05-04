/*
** EPITECH PROJECT, 2017
** matches
** File description:
** structs for graphical
*/

#ifndef _HUD_H_
	#define _HUD_H_

	typedef struct hud_s hud_t;

	struct hud_s {
		sfFont *f_hud;
		sfText *t_coo;
	};

	//CREATE
	hud_t *create_hud(void);

	//DISPLAY
	void display_hud(rpg_t *rpg);

#endif
