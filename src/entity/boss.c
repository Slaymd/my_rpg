/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "../../include/rpg.h"

void lycan_cry(rpg_t *rpg, entity_t *ent, int count)
{
	static int verif = 0;
	static int first = 0;

	first == 0 ? sfMusic_setVolume(rpg->music, 30) : 0;
	verif == 0 ? ent->square.left = 1270, ent->square.height += 50,
	ent->square.top -= 20, sfMusic_play(ent->song) : 0;
	ent->mirror = 2;
	display_ennemy(rpg, ent, rpg->map, count);
	ent->mirror = 0;
	verif = 1;
	first++;
	first >= 199 ? sfMusic_setVolume(rpg->music, 100) : 0;
}

void display_attack(rpg_t *rpg, entity_t *ent, map_t *map, int count)
{
	if (count == 5) {
		ent->square.left = ent->square.left + 400 >= 4400 ?
		0 : ent->square.left + 400;
		detect_attack_char(ent, map) == 1 ?
		rpg->character->stat->hp -= 10 : 0;
		sfSprite_setTextureRect(ent->sprite, ent->square);
	}
	reinit_var(rpg, ent, map);
}
void attack_lycan(entity_t *ent, rpg_t *rpg)
{
	static int verif = 0;
	static int count = 0;

	verif == 0 && ent->mirror == 0 ? ent->square.left = 0, ent->square.top
	= 620, ent->square.width = 400 : 0;
	verif == 0 && ent->mirror == 1 ? ent->square.left = 0, ent->square.top
	= 1020, ent->square.width = 400 : 0;
	count++;
	display_attack(rpg, ent, rpg->map, count);
	verif++;
	count >= 5 ? count = 0 : 0;
	verif >= 120 ? verif = 0, ent->square.width = 180,
	ent->square.top = 220, ent->square.left = 0 : 0;
}

int detect_char(entity_t *ent, map_t *map)
{
	int x = map->center.x;
	int y = map->center.y;

	if (x >= ent->pos.x - 19 && x <= ent->pos.x + 19 && y >= ent->pos.y - 19
	&& y <= ent->pos.y + 19) {
		return (1);
	}
	return (0);
}

void follow_lycan(entity_t *ent, map_t *map, rpg_t *rpg, int first)
{
	int xx = map->center.x;
	int yy = map->center.y;
	static int count = 0;
	static int x = 0;

	if (ent->hp <= 0) {
		lycan_die(ent, map, rpg);
		return;
	}
	if (detect_char(ent, map) == 1 && first >= 200)
		run_char(ent, map, xx, yy);
	ent->seconds >= 0.10 ? count += 1 : 0;
	ent->mirror == 0 && count == 15 ? x++ : 0;
	ent->mirror == 1 && count == 15 ? x-- : 0;
	count = ent->mirror == 1 ? go_left_lycan(ent, count, map) :
	go_right_lycan(ent, count, map);
	x = my_if_lycan(ent, x);
	display_ennemy(rpg, ent, map, (int) count);
}
