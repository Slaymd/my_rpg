/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** move
*/

#include "../../include/rpg.h"

ptr_t func[7] = {
	{1, &deplacement_ostrich},
	{2, &deplacement_ogre},
	{3, &deplacement_lycan},
	{4, &deplacement_villager},
	{5, &deplacement_villager2},
	{6, &deplacement_villager3},
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
	int x = ent->pos.x;
	int y = ent->pos.y;
	int sx = 0;
	int sy = 0;
	shoot_t *tmp = rpg->fairy->shoot->first;

	while (tmp) {
		sy = tmp->pos_e.y;
		sx = tmp->pos_e.x;
		if (tmp->state != 0 && tmp->rect.left == 192 &&
		x >= sx - 3 && x <= sx + 3 && y  >= sy - 3 && y <= sy  + 3)
			ent->hp = ent->hp > 0 ? ent->hp -
			rpg->inv->stat->atti : 0;
		tmp = tmp->next;
	}
}

void ennemy_handling(rpg_t *rpg, map_t *map)
{
	list_t *tmp = rpg->map->entities;
	entity_t *ent = NULL;

	for (; tmp != NULL; tmp = tmp->next) {
		ent = (entity_t *)tmp->data;
		ent->time = sfClock_getElapsedTime(ent->clock);
		ent->seconds = ent->time.microseconds / 1000000.0;
		for (int i = 0; i < 7; i++) {
			ent->num == func[i].balise ?
			func[i].callback(rpg, map, ent) : 0;
		}
		detect_damage(rpg, ent);
	}
}
