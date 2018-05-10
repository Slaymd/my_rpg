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
	if (count == 5 && (ent->top < 3 || ent->top > 14)) {
		ent->square.left = ent->square.left + 200 >= 2800 ?
		2800 : ent->square.left + 200;
		sfSprite_setTextureRect(ent->sprite, ent->square);
		ent->top ++;
	}
	else if (count == 5)
		ent->top++;
	reinit_var(rpg, ent, map);
}

void dead_ogre(entity_t *ent, rpg_t *rpg)
{
	ent->verif == 0 ? ent->square.left = 0, ent->square.top
	= 800, ent->square.width = 200, ent->square.height = 300 : 0;
	ent->compt++;
	display_dead_ogre(rpg, ent, rpg->map, ent->compt);
	ent->verif++;
	ent->compt >= 5 ? ent->compt = 0 : 0;
}

void deplacement_ogre(rpg_t *rpg, map_t *map, entity_t *ent)
{
	if (ent->atk >= 0 && ent->atk < 100) {
		attack_ogre(ent, rpg);
		ent->atk++;
		return;
	}
	for (int i = 0; i == 0 && ent->hp <= 0; i++, dead_ogre(ent, rpg))
		return;
	detect_ennemy(ent, map) == 1 ? follow_ogre(ent, map, rpg) : 0;
	(int)ent->pos.x == (int)map->center.x && (int)ent->pos.y ==
	(int)map->center.y && ent->atk == -1 ? ent->atk = 0 : 0;
	ent->seconds >= 0.10 ? ent->count += 1 : 0;
	ent->x = find_x(ent, ent->count, ent->x);
	ent->x = my_if_ogre(ent, ent->x);
	ent->count = ent->mirror == 1 ? go_left_ogre(ent, ent->count, map, rpg)
	: go_right_ogre(ent, ent->count, map, rpg);
	ent->atk >= 100 && ent->hp > 0 ? ent->atk = -1 : 0;
}
