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
		int conso;
		int stack;
	} item_t;

#endif
