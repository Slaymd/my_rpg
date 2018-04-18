/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "../../include/rpg.h"

void follow_ostrich(rpg_t *rpg, entity_t *ent, map_t *map)
{
	int x = map->topleft_to_disp.x + (WIDTH / TILE_SIZE / 2);
	int y = map->topleft_to_disp.y + (HEIGHT / TILE_SIZE / 2);
	if (ent->pos.x < rpg->character->pos.x) {
		ent->pos.x += 0.125;
		my_printf("%s\n", "d");
	}
	if (ent->pos.x > rpg->character->pos.x) {
		my_printf("px = %f et ent = %f\n", ent->pos.x, rpg->character->pos.x);
		ent->pos.x -= 0.125;
		my_printf("%s\n", "g");
	}
	if (ent->pos.y > rpg->character->pos.y) {
		my_printf("px = %f et ent = %f\n", ent->pos.y, rpg->character->pos.y);
		ent->pos.y -= 0.125;
		my_printf("%s\n", "g");
	}
	my_printf("y = %d et x  = %d\n", y, x);
	if (ent->pos.y < rpg->character->pos.y) {
		//ent->pos.y += 0.125;
		my_printf("%s\n", "g");
	}
}

void follow_ogre(rpg_t *rpg, entity_t *ent, map_t *map)
{

}
