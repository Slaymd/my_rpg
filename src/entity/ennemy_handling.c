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

void detect_ennemy(rpg_t *rpg, entity_t *ent)
{
	if (rpg->character->pos.x < sfRectangleShape_getPosition(ent->rect).x
	+ sfRectangleShape_getSize(ent->rect).x && rpg->character->pos.x >
	sfRectangleShape_getPosition(ent->rect).x && rpg->character->pos.y
	< sfRectangleShape_getPosition(ent->rect).y +
	sfRectangleShape_getSize(ent->rect).y && rpg->character->pos.y >
	sfRectangleShape_getPosition(ent->rect).y)
	{
		my_printf("%s\n", "in the detecion area");
	}
}

void ennemy_handling(rpg_t *rpg, map_t *map)
{
	list_t *tmp = rpg->entities;

	for (; tmp != NULL; tmp = tmp->next) {
		//detect_ennemy(rpg, (entity_t *)tmp->data);
		for (int i = 0; i < 3; i++) {
			if (((entity_t *)tmp->data)->num == func[i].balise)
				func[i].callback(rpg, map, (entity_t *)
				{tmp->data});
		}
	}
}
