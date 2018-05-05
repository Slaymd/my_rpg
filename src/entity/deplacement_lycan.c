/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "../../include/rpg.h"

void mirror_lycan(entity_t *ent, int mirror)
{
	static int key = 0;

	if (mirror == 1 && key == 1) {
		ent->lvl += ent->lvl;
		key = 0;
	} else if (mirror == 0 && key == 0) {
		ent->lvl -= (ent->lvl / 2);
		key = 1;
	}
}

int go_left_lycan(entity_t *ent, int count, map_t *map)
{
	if (count >= 15) {
		if (can_move_here(map, ent->pos) == 1) {
			ent->pos.x += 0.5;
			return (0);
		}
		ent->pos.x -= 0.3;
		count = 0;
	}
	return (count);
}

int go_right_lycan(entity_t *ent, int count, map_t *map)
{
	if (count >= 15) {
		if (can_move_here(map, ent->pos) == 1) {
			ent->pos.x -= 0.5;
			return (0);
		}
		ent->pos.x += 0.3;
		count = 0;
	}
	return (count);
}

int my_if_lycan(entity_t *ent, int x)
{
	ent->mirror == 4 ? x = 0, ent->mirror = 0, mirror_lycan(ent, 0) : 0;
	if (ent->mirror == 3) {
		x = 20;
		ent->mirror = 1;
		mirror_lycan(ent, 1);
	} else if (x <= 0) {
		ent->mirror = 0;
		mirror_lycan(ent, 0);
	} else if (x >= 20) {
		ent->mirror = 1;
		mirror_lycan(ent, 1);
	}
	return (x);
}

void deplacement_lycan(rpg_t *rpg, map_t *map, entity_t *ent)
{
	static int count = 0;
	static int x = 0;
	static int first = -1;

	detect_ennemy(ent, map) == 1 && first == -1 ? first++ : 0;
	if (first >= 0 && first < 200) {
		lycan_cry(rpg, ent, count);
		first++;
		count = count >= 5 ? 0 : count + 1;
		return;
	}
	detect_ennemy(ent, map) == 1 ? follow_lycan(ent, map, rpg) : 0;
	ent->seconds >= 0.10 ? count += 1 : 0;
	ent->mirror == 0 && count == 15 ? x++ : 0;
	ent->mirror == 1 && count == 15 ? x-- : 0;
	count = ent->mirror == 1 ? go_left_lycan(ent, count, map) :
	go_right_lycan(ent, count, map);
	x = my_if_lycan(ent, x);
	display_ennemy(rpg, ent, map, (int) count);
}
