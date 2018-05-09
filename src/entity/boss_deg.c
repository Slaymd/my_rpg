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

void detect_blocked_x(entity_t *ent, map_t *map, int block_x)
{
	if (block_x == 2 && can_move_here(map, (pos_t)
	{ent->pos.x, ent->pos.y + 0.56, ent->pos.z}) == 1)
		ent->pos.y += 0.56;
	else if (block_x == 2 && can_move_here(map, (pos_t)
	{ent->pos.x, ent->pos.y - 0.56, ent->pos.z}) == 1)
		ent->pos.y -= 0.56;
}

void detect_blocked_y(entity_t *ent, map_t *map, int block_x, int block_y)
{
	if (block_y == 2 && block_x >= 1 && can_move_here(map, (pos_t)
		{ent->pos.x + 0.12, ent->pos.y, ent->pos.z}) == 1)
		ent->pos.x += 0.12;
	else if (block_y == 2 && block_x >= 1 && can_move_here(map, (pos_t)
		{ent->pos.x - 0.12, ent->pos.y, ent->pos.z}) == 1)
		ent->pos.x -= 0.12;
	detect_blocked_x(ent, map, block_x);

}

int run_char(entity_t *ent, map_t *map, int xx, int yy)
{
	int pos = 0;
	int block_x = 0;
	int block_y = 0;

	ent->pos.x <= xx + 0.3 && can_move_here(map,
	(pos_t){ent->pos.x + 0.12, ent->pos.y, ent->pos.z}) == 1 ?
	ent->pos.x += 0.12, ent->mirror = 3 : block_x++;
	ent->pos.x >= xx + 0.3 && can_move_here(map, (pos_t){ent->pos.x
	- 0.12, ent->pos.y, ent->pos.z}) == 1 ? ent->pos.x -= 0.12,
	ent->mirror = 4 : block_x++;
	pos = xx;
	ent->pos.y >= yy && can_move_here(map, (pos_t){ent->pos.x,
	ent->pos.y - 0.16, ent->pos.z}) == 1 ? ent->pos.y -= 0.16 : block_y++;
	ent->pos.y <= yy && can_move_here(map, (pos_t){ent->pos.x,
	ent->pos.y + 0.16, ent->pos.z}) == 1 ? ent->pos.y += 0.16 : block_y++;
	detect_blocked_y(ent, map, block_x, block_y);
	return (pos);
}
