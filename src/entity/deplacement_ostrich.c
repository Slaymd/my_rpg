/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "../../include/rpg.h"

void mirror_ostrich(entity_t *ent, int mirror)
{
	if (mirror == 1 && ent->key == 1) {
		ent->lvl += ent->lvl;
		ent->key = 0;
	} else if (mirror == 0 && ent->key == 0) {
		ent->lvl -= (ent->lvl / 2);
		ent->key = 1;
	}
}

int go_left_ostrich(entity_t *ent, int count, map_t *map)
{
	if (count >= 5) {
		if (can_move_here(map, (pos_t){ent->pos.x + 0.3,
		ent->pos.y, ent->pos.z}) == 1) {
			ent->pos.x += 0.3;
			return (0);
		}
		ent->pos.x -= 0.3;
		count = 0;
	}
	return (count);
}

int go_right_ostrich(entity_t *ent, int count, map_t *map)
{
	if (count >= 5) {
		if (can_move_here(map, ent->pos) == 1) {
			ent->pos.x -= 0.3;
			return (0);
		}
		ent->pos.x += 0.3;
		count = 0;
	}
	return (count);
}

int my_if_ostrich(entity_t *ent, int x)
{
	ent->mirror == 4 ? x = 0, ent->mirror = 0, mirror_ostrich(ent, 0) : 0;
	if (ent->mirror == 3) {
		x = 20;
		ent->mirror = 1;
		mirror_ostrich(ent, 1);
	} else if (x <= 0) {
		ent->mirror = 0;
		mirror_ostrich(ent, 0);
	} else if (x >= 100) {
		ent->mirror = 1;
		mirror_ostrich(ent, 1);
	}
	return (x);
}

void deplacement_ostrich(rpg_t *rpg, map_t *map, entity_t *ent)
{
	if (ent->hp <= 0) {
		xp_ostrich(ent, rpg);
		rand_drop_item(rpg, ent);
		ent->square.left = 1000;
		return;
	}
	detect_ennemy(ent, map) == 1 ? follow_ostrich(ent, map) : 0;
	ent->seconds >= 0.10 ? ent->count += 1 : 0;
	ent->mirror == 0 && ent->count == 5 ? ent->x++ : 0;
	ent->mirror == 1 && ent->count == 5 ? ent->x-- : 0;
	ent->x = my_if_ostrich(ent, ent->x);
	display_ennemy(rpg, ent, map, (int) ent->count);
	ent->count = ent->mirror == 1 ? go_left_ostrich(ent, ent->count, map) :
	go_right_ostrich(ent, ent->count, map);
}
