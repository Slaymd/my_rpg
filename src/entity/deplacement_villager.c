/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "../../include/rpg.h"

int detect_villager(entity_t *ent, map_t *map)
{
	int x = map->center.x;
	int y = map->center.y;

	if (x >= ent->pos.x - 1 && x <= ent->pos.x + 1 && y >= ent->pos.y - 1
	&& y <= ent->pos.y + 1) {
		return (1);
	}
	return (0);
}

void deplacement_villager(rpg_t *rpg, map_t *map, entity_t *ent)
{
	static int x = 0;

	display_ennemy(rpg, ent, map, 5);
}
