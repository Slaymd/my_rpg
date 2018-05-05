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

	verif == 0 ? ent->square.left = 1270, sfMusic_play(ent->song) : 0;
	ent->mirror = 2;
	display_ennemy(rpg, ent, rpg->map, count);
	ent->mirror = 0;
	verif = 1;
}

void display_attack(rpg_t *rpg, entity_t *ent, map_t *map, int count)
{
	if (ent->mirror == 2 && count == 5) {
		ent->square.left = ent->square.left + ent->movement >= 2500 ?
		2500 : ent->square.left + 177;
		sfSprite_setTextureRect(ent->sprite, ent->square);
	}
	reinit_var(rpg, ent, map);
}
void attack_lycan(entity_t *ent, map_t *map, rpg_t *rpg)
{
	static int verif = 0;
	static int count = 0;

	verif == 0 ? ent->square.left = 1270 : 0;
	ent->mirror = 2;
	display_attack(rpg, ent, rpg->map, count);
	count++;
	ent->mirror = 0;
	verif = 1;
}

void follow_lycan(entity_t *ent, map_t *map, rpg_t *rpg)
{
	int x = map->center.x;
	int y = map->center.y;
	static int pos = 0;
	static int attack = -1;

	pos == x ? attack = 0 : 0;
	if (attack >= 0 && attack <= 200) {
		//ent->pos.y = x;
		attack_lycan(ent, map, rpg);
		attack++;
		return;
	}
	//ent->pos.y = x;
	ent->pos.x <= x + 0.3 ? ent->pos.x += 0.12, ent->mirror = 3 : 0;
	ent->pos.x >= x + 0.3 ? ent->pos.x -= 0.12, ent->mirror = 4 : 0;
	pos = x;
	ent->pos.y >= y ? ent->pos.y -= 0.16 : 0;
	ent->pos.y <= y ? ent->pos.y += 0.16 : 0;
	attack >= 200 ? attack = -1 : 0;
}
