/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "../../include/rpg.h"

int find_x(entity_t *ent, int count, int x)
{
	ent->mirror == 0 && count == 5 ? x++ : 0;
	ent->mirror == 1 && count == 5 ? x-- : 0;
	return (x);
}

void display_dead_ogre(rpg_t *rpg, entity_t *ent, map_t *map, int count)
{
	static int top = 0;

	if (count == 5 && (top < 3 || top > 14)) {
		ent->square.left = ent->square.left + 200 >= 2800 ?
		2800 : ent->square.left + 200;
		sfSprite_setTextureRect(ent->sprite, ent->square);
		top ++;
	}
	else if (count == 5)
		top++;
	reinit_var(rpg, ent, map);
}

void dead_ogre(entity_t *ent, rpg_t *rpg)
{
	static int verif = 0;
	static int count = 0;

	verif == 0 ? ent->square.left = 0, ent->square.top
	= 800, ent->square.width = 200, ent->square.height = 300 : 0;
	count++;
	display_dead_ogre(rpg, ent, rpg->map, count);
	verif++;
	count >= 5 ? count = 0 : 0;
}

void deplacement_ogre(rpg_t *rpg, map_t *map, entity_t *ent)
{
	static int count = 0;
	static int x = 0;
	static int atk = -1;

	if (atk >= 0 && atk < 100) {
		attack_ogre(ent, rpg);
		atk++;
		return;
	}
	for (int i = 0; i == 0 && ent->hp <= 0; i++, dead_ogre(ent, rpg))
		return;
	detect_ennemy(ent, map) == 1 ? follow_ogre(ent, map, rpg) : 0;
	(int)ent->pos.x == (int)map->center.x && (int)ent->pos.y ==
	(int)map->center.y && atk == -1 ? atk = 0 : 0;
	ent->seconds >= 0.10 ? count += 1 : 0;
	x = find_x(ent, count, x);
	x = my_if_ogre(ent, x);
	count = ent->mirror == 1 ? go_left_ogre(ent, count, map, rpg) :
	go_right_ogre(ent, count, map, rpg);
	atk >= 100 && ent->hp > 0 ? atk = -1 : 0;
}
