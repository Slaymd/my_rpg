/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** object disp
*/

#include "../../../include/rpg.h"

int	disp_objects(sfRenderWindow *wd, map_t *map)
{
	list_t *objs = map->objects;
	object_t *obj = NULL;

	for (; objs != NULL; objs = objs->next) {
		obj = (object_t*)objs->data;
		if (obj->sprite != NULL)
			disp_sprite_at(wd, map, obj->sprite, obj->pos);
	}
	return (0);
}
