/*
** EPITECH PROJECT, 2017
** matches
** File description:
** inventory
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef _INVENTORY_H_
	#define _INVENTORY_H_

	typedef struct item_s {
		sfSprite *sitem;
		sfTexture *titem;
		sfVector2f pitem;
		sfIntRect ritem;
		int in_body;
		int can_e;
		int status;
		int attack;
		int def;
		int life;
		int r_life;
		int r_mana;
		int conso;
		int stack;
	} item_t;

	typedef struct stat_perso_s {
		int atti;
		int defi;
		int lifei;
		int r_lifei;
		int r_manai;
		// char *attc;
		// char *defc;
		// char *lifec;
		// char *r_lifec;
		// char *r_manac;
		text_t *attt;
		text_t *deft;
		text_t *lifet;
		text_t *r_lifet;
		text_t *r_manat;
	}stat_perso_t;

	typedef struct inv_s {
		int quit;
		int fill;
		sfVector2i pos_m;
		sfClock *clocki;
		sfTime timei;
		float seconds;
		stat_perso_t *stat;
		item_t *slot[20];
	} inv_t;

#endif
