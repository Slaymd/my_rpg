/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "../../include/rpg.h"

void mirror_lycan(entity_t *ent, int mirror)
{
	if (mirror == 1 && ent->key == 1) {
		ent->lvl += ent->lvl;
		ent->key = 0;
	} else if (mirror == 0 && ent->key == 0) {
		ent->lvl -= (ent->lvl / 2);
		ent->key = 1;
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
	} else {
		if (x >= 20) {
			ent->mirror = 1;
			mirror_lycan(ent, 1);
		}
	}
	return (x);
}

void deplacement_lycan(rpg_t *rpg, map_t *map, entity_t *ent)
{
	ent->lcry < 200 ? ent->hp = 270 : 0;
	detect_ennemy(ent, map) == 1 && ent->lcry == -1 ? ent->lcry++ : 0;
	if (ent->lcry >= 0 && ent->lcry < 200) {
		lycan_cry(rpg, ent, ent->count);
		ent->lcry++;
		ent->count = ent->count >= 5 ? 0 : ent->count + 1;
		return;
	} else if (ent->latk < 120 && ((ent->latk == 0 && ent->hp > 0) ||
	(ent->latk >= 0 && ent->hp != 0))) {
		attack_lycan(ent, rpg);
		ent->latk++;
		return;
	}
	detect_ennemy(ent, map) == 1 && ent->latk == -1 ? ent->latk = 0 : 0;
	ent->latk >= 120 && ent->hp > 0 ? ent->latk = -1 : 0;
	follow_lycan(ent, map, rpg, ent->lcry);
}
