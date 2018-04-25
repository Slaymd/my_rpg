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

	ent->seconds >= 1 ? sfMusic_play(ent->song) : 0;
	if (ent->pos.x < x) {
		if (can_move_here(map , ent->pos) == 1) {
			ent->pos.x += 0.22;
			pos = x;
			return;
		}
		pos != x && can_move_here(map, ent->pos) == 0 ? ent->pos.x -= 0.22 : 0;
		ent->mirror = 4;
		pos = x;
	} else if (ent->pos.x > x)
		pos = my_right_ostrich(ent, map, pos, x);
	ent->pos.y >= y ? ent->pos.y += 0.3 : 0;
	ent->pos.y <= y ? ent->pos.y -= 0.3 : 0;
}

void follow_ogre(entity_t *ent, map_t *map, character_t *character)
{
	int x = map->center.x;
	int y = map->center.y;
	static int pos = 0;

//	ent->seconds >= 1 ? sfMusic_play(ent->song) : 0;
	if (pos == x) {
		character->hp -= 0.2;
	}
	ent->pos.x <= x + 0.3 ? ent->pos.x += 0.12, ent->mirror = 3 : 0;
	ent->pos.x >= x + 0.3 ? ent->pos.x -= 0.12, ent->mirror = 4 : 0;
	pos = x;
	ent->pos.y >= y ? ent->pos.y -= 0.16 : 0;
	ent->pos.y <= y ? ent->pos.y += 0.16 : 0;
}
