/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** move
*/

#include "../../include/rpg.h"

ptr_t func[3] = {
	{1, &deplacement_ostrich},
	{2, &deplacement_ogre},
	{0, NULL}
};

int detect_ennemy(entity_t *ent, map_t *map)
{
	int x = map->topleft_to_disp.x + (WIDTH / TILE_SIZE / 2);
	int y = map->topleft_to_disp.y + (HEIGHT / TILE_SIZE / 2);

	if (x >= ent->pos.x - 3 && x <= ent->pos.x + 3 && y >= ent->pos.y - 3
	&& y <= ent->pos.y + 3) {
		return (1);
	}
	return (0);
}

void ennemy_handling(rpg_t *rpg, map_t *map)
{
	list_t *tmp = rpg->entities;

	for (; tmp != NULL; tmp = tmp->next) {
		((entity_t *)tmp->data)->time =
		sfClock_getElapsedTime(((entity_t *)tmp->data)->clock);
		((entity_t *)tmp->data)->seconds =
		((entity_t *)tmp->data)->time.microseconds / 1000000.0;
		for (int i = 0; i < 3; i++) {
			if (((entity_t *)tmp->data)->num == func[i].balise)
				func[i].callback(rpg, map, (entity_t *)
				{tmp->data});
		}
	}
}
