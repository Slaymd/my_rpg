/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** move
*/

#include "../../include/rpg.h"

ptr_t func[5] = {
	{1, &deplacement_ostrich},
	{2, &deplacement_ogre},
	{3, &deplacement_lycan},
	{4, &deplacement_villager},
	{0, NULL}
};

int detect_ennemy(entity_t *ent, map_t *map)
{
	int x = map->center.x;
	int y = map->center.y;

	if (x >= ent->pos.x - 4 && x <= ent->pos.x + 4 && y >= ent->pos.y - 4
	&& y <= ent->pos.y + 4) {
		return (1);
	}
	return (0);
}

void detect_damage(rpg_t *rpg, entity_t *ent)
{
	float x = ent->pos.x + (WIDTH / TILE_SIZE / 2);
	float y = ent->pos.y + (HEIGHT / TILE_SIZE / 2);
	shoot_t *tmp = rpg->fairy->shoot->first;

	while (tmp) {
		if (tmp->state != 0 && tmp->rect.left < 4800)
			// if (x == tmp->pos_e.x && y == tmp->pos_e.y)
		tmp = tmp->next;
	}
}

void ennemy_handling(rpg_t *rpg, map_t *map)
{
	list_t *tmp = rpg->entities;

	for (; tmp != NULL; tmp = tmp->next) {
		((entity_t *)tmp->data)->time =
		sfClock_getElapsedTime(((entity_t *)tmp->data)->clock);
		((entity_t *)tmp->data)->seconds =
		((entity_t *)tmp->data)->time.microseconds / 1000000.0;
		for (int i = 0; i < 5; i++) {
			((entity_t *)tmp->data)->num == func[i].balise ?
			func[i].callback(rpg, map, (entity_t *)
			{tmp->data}) : 0;
		}
		detect_damage(rpg, (entity_t *) {tmp->data});
	}
}
