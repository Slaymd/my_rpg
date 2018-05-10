/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "../../include/rpg.h"

void display_dead(rpg_t *rpg, entity_t *ent, map_t *map, int count)
{
	static int top = 0;

	if (count == 5 && (top < 3 || top > 14)) {
		ent->square.left = ent->square.left + 400 >= 2800 ?
		2800 : ent->square.left + 400;
		sfSprite_setTextureRect(ent->sprite, ent->square);
		top ++;
	}
	else if (count == 5)
		top++;
	reinit_var(rpg, ent, map);
}

void lycan_die(entity_t *ent, rpg_t *rpg)
{
	static int verif = 0;
	static int count = 0;

	verif == 0 ? ent->square.left = 0, ent->square.top
	= 1300, ent->square.width = 400, ent->square.height = 300 : 0;
	count++;
	display_dead(rpg, ent, rpg->map, count);
	verif++;
	count >= 5 ? count = 0 : 0;
}
