/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "../../include/rpg.h"

<<<<<<< HEAD
void follow_ostrich(entity_t *ent, map_t *map)
{
	int x = map->topleft_to_disp.x + (WIDTH / TILE_SIZE / 2);
	int y = map->topleft_to_disp.y + (HEIGHT / TILE_SIZE / 2);

	ent->pos.x <= x + 0.3 ? ent->pos.x += 0.255, ent->mirror = 3 : 0;
	ent->pos.x >= x + 0.3 ? ent->pos.x -= 0.255, ent->mirror = 4 : 0;
	ent->pos.y >= y ? ent->pos.y -= 0.355 : 0;
	ent->pos.y <= y ? ent->pos.y += 0.355 : 0;
}

void follow_ogre(entity_t *ent, map_t *map)
{
	int x = map->topleft_to_disp.x + (WIDTH / TILE_SIZE / 2);
	int y = map->topleft_to_disp.y + (HEIGHT / TILE_SIZE / 2);

	ent->pos.x <= x + 0.3 ? ent->pos.x += 0.255, ent->mirror = 3 : 0;
	ent->pos.x >= x + 0.3 ? ent->pos.x -= 0.255, ent->mirror = 4 : 0;
	ent->pos.y >= y ? ent->pos.y -= 0.355 : 0;
	ent->pos.y <= y ? ent->pos.y += 0.355 : 0;
=======
void follow_ostrich(rpg_t *rpg, entity_t *ent, map_t *map)
{
	int x = map->topleft_to_disp.x + (WIDTH / TILE_SIZE / 2);
	int y = map->topleft_to_disp.y + (HEIGHT / TILE_SIZE / 2);
	if (ent->pos.x < rpg->character->pos.x) {
		ent->pos.x += 0.125;
		// my_printf("%s\n", "d");
	}
	if (ent->pos.x > rpg->character->pos.x) {
		// my_printf("px = %f et ent = %f\n", ent->pos.x, rpg->character->pos.x);
		ent->pos.x -= 0.125;
		// my_printf("%s\n", "g");
	}
	if (ent->pos.y > rpg->character->pos.y) {
		// my_printf("px = %f et ent = %f\n", ent->pos.y, rpg->character->pos.y);
		ent->pos.y -= 0.125;
		// my_printf("%s\n", "g");
	}
	// my_printf("y = %d et x  = %d\n", y, x);
	if (ent->pos.y < rpg->character->pos.y) {
		//ent->pos.y += 0.125;
		// my_printf("%s\n", "g");
	}
}

void follow_ogre(rpg_t *rpg, entity_t *ent, map_t *map)
{

>>>>>>> c3dba5096672bb940d60cf14f4c07f8ed14f9028
}
