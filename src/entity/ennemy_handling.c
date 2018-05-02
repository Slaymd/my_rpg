/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** move
*/

#include "../../include/rpg.h"

ptr_t func[4] = {
	{1, &deplacement_ostrich},
	{2, &deplacement_ogre},
	{3, &deplacement_lycan},
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
	if (rpg->fairy->shoot->first != NULL) {
		printf("shoot = %f | %f\n", rpg->fairy->shoot->first->pos_e.x, rpg->fairy->shoot->first->pos_e.y);
		printf("ent   = %f | %f\n", ent->pos.x, ent->pos.y);
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
		for (int i = 0; i < 3; i++) {
			if (((entity_t *)tmp->data)->num == func[i].balise) {
				func[i].callback(rpg, map, (entity_t *)
				{tmp->data});
			}
		}
		detect_damage(rpg, (entity_t *) {tmp->data});
	}
}
