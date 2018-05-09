/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "../../include/rpg.h"

int detect_attack_char(entity_t *ent, map_t *map)
{
	int x = map->center.x;
	int y = map->center.y;

	if (x >= ent->pos.x - 5 && x <= ent->pos.x + 5 && y >= ent->pos.y - 2
	&& y <= ent->pos.y + 2) {
		return (1);
	}
	return (0);
}

int run_char(entity_t *ent, map_t *map, int xx, int yy)
{
	int pos = 0;

	ent->pos.x <= xx + 0.3 && can_move_here(map,
	(pos_t){ent->pos.x + 0.12, ent->pos.y, ent->pos.z}) == 1 ?
	ent->pos.x += 0.12, ent->mirror = 3 : 0;
	ent->pos.x >= xx + 0.3 && can_move_here(map, (pos_t){ent->pos.x
	- 0.12, ent->pos.y, ent->pos.z}) == 1 ? ent->pos.x -= 0.12,
	ent->mirror = 4 : 0;
	pos = xx;
	ent->pos.y >= yy && can_move_here(map, (pos_t){ent->pos.x,
	ent->pos.y - 0.16, ent->pos.z}) == 1 ? ent->pos.y -= 0.16 : 0;
	ent->pos.y <= yy && can_move_here(map, (pos_t){ent->pos.x,
	ent->pos.y + 0.16, ent->pos.z}) == 1 ? ent->pos.y += 0.16 : 0;
	return (pos);
}
