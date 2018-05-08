/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "../../include/rpg.h"

void mirror_ogre(entity_t *ent, int mirror)
{
	static int key = 1;

	if (mirror == 1 && key == 1) {
		ent->lvl += ent->lvl;
		key = 0;
	} else if (mirror == 0 && key == 0) {
		ent->lvl -= (ent->lvl / 2);
		key = 1;
	}
}

int go_left_ogre(entity_t *ent, int count, map_t *map)
{
	if (count >= 5) {
		if (can_move_here(map, ent->pos) == 1) {
			ent->pos.x += 0.15;
			return (0);
		}
		ent->pos.x -= 0.15;
		count = 0;
	}
	return (count);
}

int go_right_ogre(entity_t *ent, int count, map_t *map)
{
	if (count >= 5) {
		if (can_move_here(map, ent->pos) == 1) {
			ent->pos.x -= 0.15;
			return (0);
		}
		ent->pos.x += 0.15;
		count = 0;
	}
	return (count);
}

int my_if_ogre(entity_t *ent, int x)
{
	ent->mirror == 4 ? x = 0, ent->mirror = 0, mirror_ogre(ent, 0) : 0;
	if (ent->mirror == 3) {
		x = 20;
		ent->mirror = 1;
		mirror_ogre(ent, 1);
	} else if (x <= 0) {
		ent->mirror = 0;
		mirror_ogre(ent, 0);
	} else if (x >= 20) {
		ent->mirror = 1;
		mirror_ogre(ent, 1);
	}
	return (x);
}

void deplacement_ogre(rpg_t *rpg, map_t *map, entity_t *ent)
{
	static int count = 0;
	static int x = 0;
	static int atk = -1;
	int xx = map->center.x;
	int yy = map->center.y;

	if (atk >= 0 && atk < 100) {
		attack_ogre(ent, rpg);
		atk++;
		return;
	}
	detect_ennemy(ent, map) == 1 ?
	follow_ogre(ent, map, rpg->character) : 0;
	(int)ent->pos.x == xx && (int)ent->pos.y == yy
	&& atk == -1 ? atk = 0 : 0;
	ent->seconds >= 0.10 ? count += 1 : 0;
	ent->mirror == 0 && count == 5 ? x++ : 0;
	ent->mirror == 1 && count == 5 ? x-- : 0;
	x = my_if_ogre(ent, x);
	display_ennemy(rpg, ent, map, (int) count);
	count = ent->mirror == 1 ? go_left_ogre(ent, count, map) :
	go_right_ogre(ent, count, map);
	atk >= 100 ? atk = -1 : 0;
}
