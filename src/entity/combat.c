/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "../../include/rpg.h"

int my_right_ostrich(entity_t *ent, map_t *map, int pos, int x)
{
	if (can_move_here(map , ent->pos) == 1) {
		ent->pos.x -= 0.22;
		pos = x;
		return (pos);
	}
	pos != x && can_move_here(map, ent->pos) == 0 ? ent->pos.x += 0.22 : 0;
	pos = x;
	ent->mirror = 3;
	return (pos);
}

void follow_ostrich(entity_t *ent, map_t *map)
{
	int x = map->center.x;
	int y = map->center.y;
	static int pos = 0;

	if (ent->pos.x < x) {
		if (can_move_here(map , ent->pos) == 1) {
			ent->pos.x += 0.22;
			pos = x;
			return;
		}
		pos != x && can_move_here(map, ent->pos) == 1 ?
		ent->pos.x -= 0.22 : 0;
		ent->mirror = 4;
		pos = x;
	} else if (ent->pos.x > x)
		pos = my_right_ostrich(ent, map, pos, x);
	ent->pos.y >= y ? ent->pos.y += 0.3 : 0;
	ent->pos.y <= y ? ent->pos.y -= 0.3 : 0;
}

void display_attack_ogre(rpg_t *rpg, entity_t *ent, map_t *map, int count)
{
	if (count == 5) {
		ent->square.left = ent->square.left + 200 >= 1800 ?
		0 : ent->square.left + 200;
		sfSprite_setTextureRect(ent->sprite, ent->square);
	}
	reinit_var(rpg, ent, map);
}

void attack_ogre(entity_t *ent, rpg_t *rpg)
{
	static int verif = 0;
	static int count = 0;

	verif == 0 && ent->mirror == 0 ? ent->square.left = 0, ent->square.top
	= 440, ent->square.width = 180 : 0;
	verif == 0 && ent->mirror == 1 ? ent->square.left = 0, ent->square.top
	= 660, ent->square.width = 180 : 0;
	count++;
	display_attack_ogre(rpg, ent, rpg->map, count);
	verif++;
	count >= 5 ? count = 0 : 0;
	verif >= 100 ? verif = 0, rpg->character->stat->hp -= 20,
	ent->square.width = 140, ent->square.top = 150,
	ent->square.left = 0 : 0;
}

void follow_ogre(entity_t *ent, map_t *map, rpg_t *rpg)
{
	int x = map->center.x;
	int y = map->center.y;
	static int pos = 0;

	ent->pos.x <= x + 0.3 ? ent->pos.x += 0.09, ent->mirror = 3 : 0;
	ent->pos.x >= x + 0.3 ? ent->pos.x -= 0.09, ent->mirror = 4 : 0;
	pos = x;
	ent->pos.y >= y ? ent->pos.y -= 0.11 : 0;
	ent->pos.y <= y ? ent->pos.y += 0.11 : 0;
	display_ennemy(rpg, ent, map, 5);
}
