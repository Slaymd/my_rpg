/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** rpg header
*/

#ifndef _ENNEMY_H_
#define _ENNEMY_H_

	typedef struct ennemy_s ennemy_t;

	struct ennemy_s {
		int lvl;
		int type;
		int stat;
		int ennemy_range;
		sfRectangleShape *rect;
		sfIntRect square;
		void(*callback)();
		sfSprite *sprite;
		sfTexture *texture;
		pos_t pos;
	};

#endif
