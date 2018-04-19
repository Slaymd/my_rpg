/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "../../include/rpg.h"

void follow_ostrich(entity_t *ent, map_t *map)
{
	int x = map->topleft_to_disp.x + (WIDTH / TILE_SIZE / 2);
	int y = map->topleft_to_disp.y + (HEIGHT / TILE_SIZE / 2);

	ent->pos.x <= x + 0.3 ? ent->pos.x += 0.255, ent->mirror = 3 : 0;
	ent->pos.x >= x + 0.3 ? ent->pos.x -= 0.255, ent->mirror = 4 : 0;
	ent->pos.y >= y ? ent->pos.y -= 0.355 : 0;
	ent->pos.y <= y ? ent->pos.y += 0.355 : 0;
}

void follow_ogre(entity_t *ent, map_t *map)
{
	int x = map->topleft_to_disp.x + (WIDTH / TILE_SIZE / 2);
	int y = map->topleft_to_disp.y + (HEIGHT / TILE_SIZE / 2);

	ent->pos.x <= x + 0.3 ? ent->pos.x += 0.255, ent->mirror = 3 : 0;
	ent->pos.x >= x + 0.3 ? ent->pos.x -= 0.255, ent->mirror = 4 : 0;
	ent->pos.y >= y ? ent->pos.y -= 0.355 : 0;
	ent->pos.y <= y ? ent->pos.y += 0.355 : 0;
}
