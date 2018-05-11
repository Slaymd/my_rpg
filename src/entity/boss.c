/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "../../include/rpg.h"

void lycan_cry(rpg_t *rpg, entity_t *ent, int count)
{
	ent->first == 0 ? sfMusic_setVolume(rpg->music, 30) : 0;
	ent->verif == 0 ? ent->square.left = 1270, ent->square.height += 50,
	ent->square.top -= 20, sfMusic_play(ent->song) : 0;
	ent->mirror = 2;
	display_ennemy(rpg, ent, rpg->map, count);
	ent->mirror = 0;
	ent->verif = 1;
	ent->first++;
	ent->first >= 199 ? sfMusic_setVolume(rpg->music, 100),
	sfMusic_destroy(ent->song), ent->first = 0 : 0;
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
	ent->verif2 == 0 && ent->mirror == 0 ? ent->square.left = 0,
	ent->square.top = 620, ent->square.width = 400 : 0;
	ent->verif2 == 0 && ent->mirror == 1 ? ent->square.left = 0,
	ent->square.top = 1020, ent->square.width = 400 : 0;
	ent->lcount++;
	display_attack(rpg, ent, rpg->map, ent->lcount);
	ent->verif2++;
	ent->lcount >= 5 ? ent->lcount = 0 : 0;
	ent->verif2 >= 120 ? ent->verif2 = 0, ent->square.width = 180,
	ent->square.top = 220, ent->square.left = 0 : 0;
}

int detect_char(entity_t *ent, map_t *map)
{
	int x = map->center.x;
	int y = map->center.y;

	if (x >= ent->pos.x - 19 && x <= ent->pos.x + 19 &&
	y >= ent->pos.y - 19 && y <= ent->pos.y + 19) {
		return (1);
	}
	return (0);
}

void follow_lycan(entity_t *ent, map_t *map, rpg_t *rpg, int first)
{
	int xx = map->center.x;
	int yy = map->center.y;

	if (ent->hp <= 0) {
		lycan_die(ent, rpg);
		rand_drop_item(rpg, ent);
		return;
	}
	if (detect_char(ent, map) == 1 && first >= 200)
		run_char(ent, map, xx, yy);
	ent->seconds >= 0.10 ? ent->lcount2 += 1 : 0;
	ent->mirror == 0 && ent->lcount2 == 15 ? ent->lx++ : 0;
	ent->mirror == 1 && ent->lcount2 == 15 ? ent->lx-- : 0;
	ent->lcount2 = ent->mirror == 1 ? go_left_lycan(ent, ent->lcount2, map)
	: go_right_lycan(ent, ent->lcount2, map);
	ent->lx = my_if_lycan(ent, ent->lx);
	display_ennemy(rpg, ent, map, ent->lcount2);
}
